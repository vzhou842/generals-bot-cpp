#include "Bot.h"

#include <chrono>
#include <thread>

using std::cout;
using std::cerr;
using std::endl;

const string address = "http://botws.generals.io";

void sleep_for(int ms) {
	std::this_thread::sleep_for(std::chrono::milliseconds(ms));
}

Bot::Bot(string user_id, function<void()> onConnect): user_id(user_id) {
	cout << "Connecting to " << address << endl;
	client.set_open_listener(onConnect);
	client.connect(address);
}

void Bot::Login(string username) {
	sio::message::list args;
	args.push(user_id);
	args.push(username);
	client.socket()->emit("set_username", args);
	cout << "Logged in as " << username << endl;
}

void Bot::JoinCustom(string room_id) {
	this->room_id = room_id;

	sio::message::list args(room_id);
	args.push(user_id);

	client.socket()->emit("join_private", args);
	sleep_for(500);
	cout << "Joined custom game " << room_id << endl;
}

void Bot::SetForceStart(bool force) {
	if (!room_id.empty()) {
		sio::message::list args(room_id);
		args.push(sio::bool_message::create(force));

		client.socket()->emit("set_force_start", args);
		cout << "Set force start for room " << room_id << " to " << force << endl;
	} else {
		cerr << "ERROR: Trying to set force start when bot is not in a room!" << endl;
	}
}
