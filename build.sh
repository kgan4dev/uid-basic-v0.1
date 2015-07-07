#!/bin/bash

#Looking for the PWD Path in this machine
path=`pwd`
arch=$(uname -m)

if [ $arch == 'i686' ]; then
	TARGET_CPU='x86'
elif [ $arch == 'armv61' ]; then
	TARGET_CPU='arm'
fi

# building alljoyn component services
printf "Building started for AllJoyn component services.\n"
cd $path/core/alljoyn/core/alljoyn/
if [ $TARGET_CPU == 'x86' ]; then
	scons WS=off BINDINGS=cpp SERVICES="about,notification,controlpanel"
elif [ $TARGET_CPU == 'arm' ]; then
	scons WS=off BINDINGS=cpp CPU=arm OE_BASE=/usr SERVICES="about,notification,controlpanel"
fi

printf "Checking Alljoyn About Service . . .			"
if [ -f $path/core/alljoyn/core/alljoyn/build/linux/$TARGET_CPU/debug/dist/about/bin/AboutClient ]; then
	printf "Build successful.!\n"
else
	printf "\nSomething went wrong.!\n"
	exit
fi

printf "Checking Alljoyn notification Consumer Service . . .	"
if [ -f $path/core/alljoyn/core/alljoyn/build/linux/$TARGET_CPU/debug/dist/notification/bin/ConsumerService ]; then
	printf "Build successful.!\n"
else
	printf "\nSomething went wrong.!\n"
	exit
fi

printf "Checking Alljoyn notification Producer Service . . .	"
if [ -f $path/core/alljoyn/core/alljoyn/build/linux/$TARGET_CPU/debug/dist/notification/bin/ProducerService ]; then
	printf "Build successful.!\n"
else
	printf "\nSomething went wrong.!\n"
	exit
fi

#printf "Checking Alljoyn Onboarding Client Service . . .	"
#if [ -f $path/core/alljoyn/core/alljoyn/build/linux/$TARGET_CPU/debug/dist/onboarding/bin/OnboardingClient ]; then
#	printf "Build successful.!\n"
#else
#	printf "\nSomething went wrong.!\n"
#	exit
#fi

#printf "Checking Alljoyn Onboarding Daemon Service . . .        "
#if [ -f $path/core/alljoyn/core/alljoyn/build/linux/$TARGET_CPU/debug/dist/onboarding/bin/onboardingdaemon ]; then
#       printf "Build successful.!\n"
#else
#       printf "\nSomething went wrong.!\n"
#       exit
#fi


printf "Checking Alljoyn Control Panel Service . . .		"
if [ -f $path/core/alljoyn/core/alljoyn/build/linux/$TARGET_CPU/debug/dist/controlpanel/bin/ControlPanelController ]; then
	printf "Build successful.!\n"
else
	printf "\nSomething went wrong.!\n"
	exit
fi

cd $path
printf "\nAlljoyn component services build successfully Done.!\n"
