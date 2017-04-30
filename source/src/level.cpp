#include "level.h"
#include "graphics.h"
#include "globals.h"
#include "tinyxml2.h"

#include "SDL.h"

#include <sstream>
#include <algorithm>
#include <cmath>


#define STUBBED(x) printf("STUBBED: %s",x);

using namespace tinyxml2;

Level::Level(){};
 
Level::Level(std::string mapName, Vector2 spawnPoint, Graphics &graphics) : 
	_mapName(mapName),
	_spawnPoint(spawnPoint),
	_size(Vector2(0,0))
{
		this->loadMap(mapName, graphics);
}


Level::~Level(){};


void Level::loadMap(std::string mapName, Graphics &graphics){
	/*
	* Parse the .tmx file
	*/
	XMLDocument doc;
	std::stringstream ss;
	ss << "../../assets/maps/" << mapName << ".tmx";
	doc.LoadFile(ss.str().c_str());
	XMLElement* mapNode = doc.FirstChildElement("map");
	/*
	* Get map's width and height and store it in _map
	*/
	int width, height;
	mapNode->QueryIntAttribute("width", &width);
	mapNode->QueryIntAttribute("height", &height);
	this->_size = Vector2(width, height);

	/*ss
	* Get tiles' width and height and store it in _tileSize
	*/
	int tileWidth, tileHeight;
	mapNode->QueryIntAttribute("tilewidth", &tileWidth);
	mapNode->QueryIntAttribute("tileheight", &tileHeight);
	printf("TILE WIDTH: %d",&tileWidth);
	printf("TILE HEIGH: %d",&tileHeight);
	this->_tileSize = Vector2(tileWidth, tileHeight);

	/*
	* load the tilesets
	*/
	XMLElement* pTileset = mapNode->FirstChildElement("tileset");
	if ( pTileset != NULL ){
		while( pTileset ){
			int firstgid;
			const char* source = pTileset->FirstChildElement("image")->Attribute("source");
			char* path;
			std::stringstream ss;
			ss << "../../assets/tilesets/" << source;
			pTileset->QueryIntAttribute("firstgid", &firstgid);
			SDL_Texture* tex = SDL_CreateTextureFromSurface(graphics.getRenderer(), graphics.loadImage(ss.str()));
			this->_tilesets.push_back(Tileset(tex, firstgid));

			pTileset = pTileset->NextSiblingElement("tileset");
		}
	}
	/*
	* load the layers
	*/
	XMLElement* pLayer = mapNode->FirstChildElement("layer");
	if ( pLayer != NULL ){
		while ( pLayer ){
			//Loading the data element
			XMLElement* pData = pLayer->FirstChildElement("data");
			if (pData != NULL){
				while (pData){
					// Loading the tile element
					XMLElement* pTile = pData->FirstChildElement("tile");
					if ( pTile != NULL ){
						int tileCounter = 0;
						while (pTile){
							// Build each individual tile here.
							// if gid == 0, no tile should be drawn. continue loop.
							if (pTile->IntAttribute("gid") == 0) {
								tileCounter++;
								if (pTile->NextSiblingElement("tile")){
									pTile = pTile->NextSiblingElement("tile");
									continue;
								} else {
									break;
								}
							}
							// Get the tileset for this gid.
							int gid = pTile->IntAttribute("gid");
							Tileset tls;
							for (int i = 0; i < this->_tilesets.size(); i++ ){
								printf("Reaching assign loop\n");
								printf("tilesets.size: %d\n", this->_tilesets.size());
								if(this->_tilesets[i].FirstGid <= gid){
									// This is the needed tileset
									tls = this->_tilesets.at(i);
									break;
								}
							}

							if (tls.FirstGid == -1){
								printf("No tileset found for this gid\n");
								//No tileset was found for this gid.
								tileCounter++;
								if(pTile->NextSiblingElement("tile")){
									pTile = pTile->NextSiblingElement("tile");
									continue;
								}else{
									break;
								}
							}

							// Get the position of the tile in the level.
							int xx = 0;
							int yy = 0;
							xx = tileCounter % width;
							xx *= tileWidth;
							yy += tileHeight * (tileCounter / width);
							Vector2 finalTilePosition = Vector2(xx, yy);

							//Calculate the position of the tile in tileset
							int tilesetWidth, tilesetHeight;
							SDL_QueryTexture(tls.Texture, NULL, NULL, &tilesetWidth, &tilesetHeight);
							int tsxx = gid % (tilesetWidth / tileWidth) - 1;
							tsxx *= tileWidth;
							int tsyy = 0;
							int amt = (gid / ( tilesetWidth / tileWidth ));
							tsyy = tileHeight * amt;
							Vector2 finalTilesetPosition = Vector2(tsxx, tsyy);

							//Build the tile and add it to the level's tilelist
							Tile tile(tls.Texture, Vector2(tileWidth, tileHeight),
							 finalTilesetPosition, finalTilePosition);
							this->_tileList.push_back(tile);
							tileCounter++;

							pTile = pTile->NextSiblingElement("tile");
						}
					}
					pData = pData->NextSiblingElement("data");
				}
			}
			pLayer = pLayer->NextSiblingElement("layer");
		}
	}

}


void Level::update(int elapsedTime){}


void Level::draw(Graphics &graphics){
	for (int i = 0; i < this->_tileList.size(); i++){
		this->_tileList.at(i).draw(graphics);
	}
}
