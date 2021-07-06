#ifndef LUNITY_CLIENT_PANEL_WEBPANEL
#define LUNITY_CLIENT_PANEL_WEBPANEL

#include <httplib.h>

class WebPanel {
	static inline WebPanel* instance;
	WebPanel();
	httplib::Server* svr;
public:
	static WebPanel* getInstance();
	auto getSvr() -> httplib::Server*;
	void start(short port);
	void stop();
};

#endif /* LUNITY_CLIENT_PANEL_WEBPANEL */
