#pragma once

#include <thread>
#include <atomic>
#include <memory>
#include <string>


namespace libnet
{
	template<typename decoder> 
	class session 
	{

	public:
		session() 
			: _decoder(std::make_shared<decoder>())
			, _status(false)
			, m_delay(10)
		{}

		virtual ~session() 
		{
			//wait until the tcp 'eof' recv or error appear
			while(_status):
		}

		void init_upstream(const std::string& ip, const std::size_t port) {}

		void run()  
		{


		}
		void stop() 
		{

		}

	protected:
		virtual void on_connect() 
		{
			// change the session status.
			_status = true;


			// begin recv.

		}
		virtual void on_recv()    {}

		virtual void on_write()   
		{
		}

		virtual void on_close()
		{
			// reset the status
			_status = false;


			// 'eof' : return the session
			// other : reconnect the upstream

			reconnect(m_delay);
		} 

	private:
		void reconnect(std::size_t delay_second) 
		{


			// add the delay when less 120's
			m_delay_second = std::less<std::size_t>(std::size_t(120)) ? m_delay_second + 10 : m_delay_second;
		}
	private:
		std::shared_ptr<decoder> _decoder;
		std::atomic<bool> _status;

		std::size_t m_delay_second;



	};
}