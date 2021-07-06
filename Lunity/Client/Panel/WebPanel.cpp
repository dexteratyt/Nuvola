#include "WebPanel.h"
#include "../../../Utils/Utils.h"

WebPanel::WebPanel() {
	instance = this;
	//this->svr = this->getSvr();
}

auto WebPanel::getInstance() -> WebPanel* {
	if(instance == nullptr) {
		instance = new WebPanel();
	}
	return instance;
}

// auto WebPanel::getSvr() -> httplib::Server* {
// 	if(this->svr == nullptr) {
// 		this->svr = new httplib::Server();
// 	}
// 	return this->svr;
// }

void WebPanel::start(short port) {
	// this->getSvr()->Get("/panel", [](const httplib::Request& req, httplib::Response& res) {
	// 	res.set_content("Hello World!", "text/plain");
	// });

	// this->getSvr()->listen("localhost", port);

	try
	{
		// you can pass http::InternetProtocol::V6 to Request to make an IPv6 request
		http::Request request{"http://wtfismyip.com/test"};

		// send a get request
		const auto response = request.send("GET");
		Utils::DebugF(std::string{response.body.begin(), response.body.end()});
	}
	catch (const std::exception& e)
	{
		Utils::DebugF("Request failed, error: ");
		Utils::DebugF(e.what());
	}
}

void WebPanel::stop() {
	// this->getSvr()->stop();
	// delete this->svr;
}