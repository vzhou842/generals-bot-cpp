#include <iostream>

#include <sio_client.h>

#include "Bot.h"

using std::cout;
using std::cin;
using std::endl;

int main (int argc, char *argv[])
{
	Bot bot("vzhou842_bot", [&bot]() {
		bot.Login("[Bot] vzhou482-bot");
		bot.JoinCustom("vzhou842");
		bot.SetForceStart(true);
	});

	cin.get();
}
