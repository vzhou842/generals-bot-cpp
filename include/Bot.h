#ifndef BOT_H
#define BOT_H

#import <iostream>
#import <functional>

#import <sio_client.h>

using std::string;
using std::function;

class Bot {
	sio::client client;
	string user_id;

	string room_id;

public:
	Bot(string user_id, function<void()> onConnect = NULL);

	void Login(string username);
	void JoinCustom(string room_id);
	void SetForceStart(bool force);
};

#endif
