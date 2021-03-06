#ifndef REQUESTHANDLER_HPP
# define REQUESTHANDLER_HPP

# include "Server.hpp"
# include <fcntl.h>
# include <sys/event.h>
# include <arpa/inet.h>
# include <netdb.h>
# include <unistd.h>
# include <fstream>
# include <sstream>
# include "AutoIndexGenerator.hpp"

//TODO make all the request handling stuff. (parsing etc) for alkrust
//TODO check if remaining request stuff is actually needed
//TODO change it so it has the t_servmap because multiple servers could be listening on the same port. So need to be able to go through all servers
class RequestHandler
{
	public:
		// Constructors
		RequestHandler(const t_servmap &srv_map);
		RequestHandler(const RequestHandler &copy);
		
		// Destructor
		~RequestHandler();
		
		// Operators
		RequestHandler & operator=(const RequestHandler &assign);

		// Getters
		std::string	getResponse() const;
		bool		isRequestComplete() const;
		std::string	getRemainingRequestMsg() const;
		bool		hasRemainingRequestMsg() const;
		int			getFileDescriptor() const;
		std::size_t	getFileSize() const;
		Location	*getLocation(std::string url) const;

		// Setters
		void	setResponse();
		void	addToRequestMsg(const std::string &msg);
		void	setSocket(int socket); //temp function for testing stuff
		void	setPort(int port);

		// Member Functions
		
		
	private:

		t_servmap	_srv_map; //TODO might need to be a t_servmap instead to handle servers on same port but with different server names?
		std::string	_complete_request;
		std::string	_remaining_request;
		std::string	_response_header;
		std::string	_response_body;
		bool		_is_request_complete;
		bool		_has_remaining_request;
		bool		_send_file;
		int			_client_socket;
		int			_fd;
		int			_port;
		std::size_t	_file_size;
};

#endif
