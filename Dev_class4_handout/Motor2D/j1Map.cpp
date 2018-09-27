#include "p2Defs.h"
#include "p2Log.h"
#include "j1App.h"
#include "j1Render.h"
#include "j1Textures.h"
#include "j1Map.h"
#include <math.h>

j1Map::j1Map() : j1Module(), map_loaded(false)
{
	name.create("map");
}

// Destructor
j1Map::~j1Map()
{}

// Called before render is available
bool j1Map::Awake(pugi::xml_node& config)
{
	LOG("Loading Map Parser");
	bool ret = true;

	folder.create(config.child("folder").child_value());
	
	return ret;
}

void j1Map::Draw()
{
	if(map_loaded == false)
		return;

	// TODO 6: Iterate all tilesets and draw all their 
	// images in 0,0 (you should have only one tileset for now)
	std::list<tileset_info>::const_iterator iterator;
	for (iterator = tile_list.begin(); iterator != tile_list.end(); ++iterator) {
		App->render->Blit(iterator->tilesetimage, 0, 0);
	}
}

// Called before quitting
bool j1Map::CleanUp()
{
	LOG("Unloading map");

	// TODO 2: Make sure you clean up any memory allocated
	// from tilesets / map


	map_file.reset();

	return true;
}

// Load new map
bool j1Map::Load(const char* file_name)
{
	bool ret = true;
	p2SString tmp("%s%s", folder.GetString(), file_name);
	
	pugi::xml_parse_result result = map_file.load_file(tmp.GetString());

	map_node = map_file.child("map");//Inicializando el nodo de mapa

	tile_node = map_node.child("tileset");//Inicializando el nodo tile


	if(result == NULL)
	{
		LOG("Could not load map xml file %s. pugi error: %s", file_name, result.description());
		ret = false;
	}

	if(ret == true)
	{
		// TODO 3: Create and call a private function to load and fill
		// all your map data
		Load_Fill(map_node);
		

	}

	// TODO 4: Create and call a private function to load a tileset
	// remember to support more any number of tilesets!
	Load_Tileset(tile_node);

	if(ret == true)
	{
		// TODO 5: LOG all the data loaded
		// iterate all tilesets and LOG everything
		

		
		
	}

	map_loaded = ret;

	return ret;
}
bool j1Map::Load_Fill(const pugi::xml_node& map) {

	map_info.version = map.attribute("version").as_float();
	LOG("Version: %f", map.attribute("version").as_float());

	const char* orientation = map.attribute("orientation").as_string();
	if (orientation[0] == 'r') {
		map_info.renderorder = map_renderorder::right_down;
	}
	else (map_info.renderorder = map_renderorder::right_up);

	if (orientation[0] == 'l') {
		map_info.renderorder = map_renderorder::left_down;
	}
	else (map_info.renderorder = map_renderorder::left_up);


   const char* renderorder = map.attribute("renderorder").as_string();
	if (orientation[0] == 'o') {
		map_info.orientation = map_orientation::ortogonal;
	}
	else if(orientation[0] == 'i') {
		map_info.orientation = map_orientation::isometric;
	}
	else if (orientation[0] == 's') {
		map_info.orientation = map_orientation::staggered;
	}
	else if (orientation[0] == 'h') {
		map_info.orientation = map_orientation::hexagonal;
	}
	

	map_info.height = map.attribute("height").as_uint();
	LOG("Height: %u", map.attribute("height").as_uint());

	map_info.width = map.attribute("width").as_uint();
	LOG("Width: %u", map.attribute("width").as_uint());

	map_info.tileheight = map.attribute("tileheight").as_uint();
	LOG("Tileheigh: %u", map.attribute("tileheight").as_uint());

	map_info.tilewidth = map.attribute("tilewidth").as_uint();
	LOG("Tilewidth: %u", map.attribute("tilewidth").as_uint());

	map_info.nextobject = map.attribute("nextobject").as_uint();
	LOG("nextobject: %u", map.attribute("nextobject").as_uint());
	
	return true;
};

bool j1Map::Load_Tileset(const pugi::xml_node& tile) {


	//Funcion Load Tileset
	/*tileset_info.firstgid = tile.attribute("fisrtgrid").as_uint();
	LOG("Firstgrid: %u", tile.attribute("fisrtgrid").as_uint());

	tileset_info.name = tile.attribute("name").as_string();
	LOG("Name: %u",tile.attribute("name").as_string());

	tileset_info.tilewidth = tile.attribute("tilewidth").as_uint();
	LOG("Tilewidth: %u",tile.attribute("tilewidth").as_uint());

	tileset_info.tileheight = tile.attribute("tileheight").as_uint();
	LOG("Tileheight: %u", tile.attribute("tileheight").as_uint());

	tileset_info.spaceing = tile.attribute("spaceing").as_uint();
	LOG("Spaceing: %u", tile.attribute("spaceing").as_uint());

	tileset_info.magin = tile.attribute("magin").as_uint();
	LOG("Magin: %u", tile.attribute("magin").as_uint());*/

	//Loop all possible tilesets
	for (pugi::xml_node tileset = tile; tileset; tileset = tileset.next_sibling("tileset")) {
		
		tileset_info tile_set;

	    tile_set.tilesetimage = App->tex->Load(tileset.parent().child("image").attribute("source").as_string());
		tile_set.firstgid = tileset.attribute("firstgid").as_uint();
		tile_set.name = tileset.attribute("name").value();
		tile_set.tilewidth = tileset.attribute("tilewidth").as_uint();
		tile_set.tileheight = tileset.attribute("tileheigh").as_uint();
		tile_set.spaceing = tileset.attribute("spaceing").as_uint();
		tile_set.magin = tileset.attribute("magin").as_uint();

		tile_list.push_back(tile_set);
		LOG("name: %s ", tile_set.name);
		LOG("frstgid: %u", tile_set.firstgid);
		
	}
	//TODO: Remove front and make a decent loop
	return true;

};
