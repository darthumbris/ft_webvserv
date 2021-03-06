#include "Config.hpp"

// Constructors
//TODO in constructor check if file can be opened.
//Map for server, string part is ip + port for easy checking
// for duplicates etc.
//TODO check if ip+port as a key should be instead servername or instead of a map for the server should be a vector?
Config::Config(std::string config_path)
{
	std::cout << "config filename: " << config_path << std::endl;
	//After this should parse the config


	//Examples for the parsing:
	// Config parsed new server with listen 127.0.0.1 8080
	addServer("127.0.0.1", "4242");
	// Config sees server_name test.com
	getLastServer()->addServerName("test.com");

	// Config parsed new location with dir: "/images"
	addLocation("/images");
	addLocation("/");
	getLastServer()->getLocationMap()["/"]->setAutoIndex(true);

	// Config parsed new server with listen 0.0.0.0 4242
	addServer("0.0.0.0", "7575");
}

Config::Config(const Config &copy)
{
	(void) copy;
}


// Destructor
Config::~Config()
{
}


// Operators
Config & Config::operator=(const Config &assign)
{
	(void) assign;
	return *this;
}

//TODO make proper getter/setter and member functions.

//TODO make a parseconfig function which goes through the config
// and adds new servers and locations (to the corresponding servers)

// Getters
t_servmap	Config::getServerMap() const
{
	return this->_server;
}

Server	*Config::getLastServer()
{
	return (_server.back());
}



// Member Functions
void	Config::addServer(std::string ip, std::string port)
{
	std::string	server_key = ip + ":" +  port;
	// if (_server.find(server_key) != _server.end())
	// 	std::cout << "Error: duplicate server in config" << std::endl; //Should throw ?
	_server.push_back(new Server());
	// _server.insert(std::make_pair(server_key, new Server()));
	_server.back()->setServerIp(ip);
	_server.back()->addServerPort(std::stoi(port));
}

void	Config::addLocation(std::string location_dir)
{
	Server		*server;
	t_locmap	location;

	server = getLastServer();
	location = server->getLocationMap();
	if (location.size() && location.find(location_dir) != location.end())
		std::cout << "Error: duplicate location in config" << std::endl; // Should throw ?
	server->addLocationToServer(location_dir);
}
