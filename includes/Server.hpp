#ifndef SERVER_HPP
# define SERVER_HPP

# include <iostream>
# include <string>
# include <map>

class Location;

class Server
{
	public:
		// Constructors
		Server();
		Server(const Server &copy);
		
		// Destructor
		~Server();
		
		// Operators
		Server & operator=(const Server &assign);
		
	private:
		int								_client_body_size;
		int								_server_fd;
		std::string						_server_name;
		std::string						_server_ip;
		std::string						_server_port;
		std::string						_root;
		std::string						_error_page;
		std::map<std::string, Location>	_location;
};

#endif