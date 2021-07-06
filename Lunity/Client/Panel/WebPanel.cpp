#include "WebPanel.h"

WebPanel::WebPanel() {
	instance = this;
	this->svr = this->getSvr();
}

auto WebPanel::getInstance() -> WebPanel* {
	if(instance == nullptr) {
		instance = new WebPanel();
	}
	return instance;
}

auto WebPanel::getSvr() -> httplib::Server* {
	if(this->svr == nullptr) {
		this->svr = new httplib::Server();
	}
	return this->svr;
}

void WebPanel::start(short port) {
	this->getSvr()->Get("/panel", [](const httplib::Request& req, httplib::Response& res) {
		res.set_content("Hello World!", "text/plain");
	});

	this->getSvr()->listen("localhost", port);
}

void WebPanel::stop() {
	this->getSvr()->stop();
	delete this->svr;
}