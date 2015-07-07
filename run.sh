#!/bin/bash

arg=$1
path=`pwd`
arch=$(uname -m)

if [ -z "$arg" ]; then
	printf "USAGE: ./run.sh {start/stop/status/restart}\n"
	exit
fi

if [ $arch == 'i686' ]; then
        TARGET_CPU='x86'
elif [ $arch == 'armv61' ]; then
        TARGET_CPU='arm'
fi

# Running Alljoyn component services
if [ $arg == 'start' ]; then
	export LD_LIBRARY_PATH=$path/core/alljoyn/core/alljoyn/build/linux/$TARGET_CPU/debug/dist/cpp/lib:$path/core/alljoyn/core/alljoyn/build/linux/$TARGET_CPU/debug/dist/about/lib:$path/core/alljoyn/core/alljoyn/build/linux/$TARGET_CPU/debug/dist/notification/lib:$path/core/alljoyn/core/alljoyn/build/linux/$TARGET_CPU/debug/dist/services_common/lib:$path/core/alljoyn/core/alljoyn/build/linux/$TARGET_CPU/debug/dist/onboarding/lib:$path/core/alljoyn/core/alljoyn/build/linux/$TARGET_CPU/debug/dist/config/lib:$path/core/alljoyn/core/alljoyn/build/linux/$TARGET_CPU/debug/dist/controlpanel/lib:$LD_LIBRARY_PATH

	printf "Starting Alljoyn component services . . . \n"

	printf "\nAbout Client service 		\n"
	if [ ! -z "$(ps | grep "AboutClient" | awk '{print $1}')" ];then
		printf "Service already running. . . \n"
	else
		printf "Service Starting. . .                   "
                $path/core/alljoyn/core/alljoyn/build/linux/$TARGET_CPU/debug/dist/about/bin/AboutClient >> $path/logs/alljoyn/AboutClient.log 2>&1 &
                printf "Done\n"
	fi

	printf "\nNotification Consumer service	\n"
	if [ ! -z "$(ps | grep "ConsumerService" | awk '{print $1}')" ];then
		printf "Service already running. . . \n"
	else
		printf "Service Starting. . .                   "
		$path/core/alljoyn/core/alljoyn/build/linux/$TARGET_CPU/debug/dist/notification/bin/ConsumerService >> $path/logs/alljoyn/ConsumerService.log 2>&1 &
                printf "Done\n"
	fi

#	printf "\nOnboarding Client service	\n"
#	if [ ! -z "$(ps | grep "OnboardingClien" | awk '{print $1}')" ];then
#		printf "Service already running. . . \n"
#	else
#		printf "Service Starting. . .                   "
#		$path/core/alljoyn/core/alljoyn/build/linux/$TARGET_CPU/debug/dist/onboarding/bin/OnboardingClient >> $path/logs/alljoyn/OnboardingClient.log 2>&1 &
#                printf "Done\n"
#	fi

#	printf "\nOnboarding Daemon service	\n"
#	if [ ! -z "$(ps | grep "onboardingdaemo" | awk '{print $1}')" ];then
#		printf "Service already running. . . \n"
#	else
#		printf "Service Starting. . .                   "
#		$path/core/alljoyn/core/alljoyn/build/linux/$TARGET_CPU/debug/dist/onboarding/bin/onboardingdaemon >> $path/logs/alljoyn/Onboardingdaemon.log 2>&1 &
#                printf "Done\n"
#	fi

	printf "\nControl Panel service	\n"
	if [ ! -z "$(ps | grep "ControlPanelCon" | awk '{print $1}')" ];then
		printf "Service already running. . . \n"
	else
		printf "Service Starting. . .                   "
		$path/core/alljoyn/core/alljoyn/build/linux/$TARGET_CPU/debug/dist/controlpanel/bin/ControlPanelController >> $path/logs/alljoyn/ControlPanelController.log 2>&1 &
                printf "Done\n"
	fi

#	printf "Notification Producer service	"
#	$path/core/alljoyn/core/alljoyn/build/linux/$TARGET_CPU/debug/dist/notification/bin/ProducerService >> $path/logs/alljoyn/ProducerService.log  2>&1 &
#	printf "Done\n\n"
	printf "\nAlljoyn component services started Successfully.!\n"
elif [ $arg == 'restart' ];then
	export LD_LIBRARY_PATH=$path/core/alljoyn/core/alljoyn/build/linux/$TARGET_CPU/debug/dist/cpp/lib:$path/core/alljoyn/core/alljoyn/build/linux/$TARGET_CPU/debug/dist/about/lib:$path/core/alljoyn/core/alljoyn/build/linux/$TARGET_CPU/debug/dist/notification/lib:$path/core/alljoyn/core/alljoyn/build/linux/$TARGET_CPU/debug/dist/services_common/lib:$path/core/alljoyn/core/alljoyn/build/linux/$TARGET_CPU/debug/dist/onboarding/lib:$path/core/alljoyn/core/alljoyn/build/linux/$TARGET_CPU/debug/dist/config/lib:$path/core/alljoyn/core/alljoyn/build/linux/$TARGET_CPU/debug/dist/controlpanel/lib:$LD_LIBRARY_PATH

	printf "Restarting Alljoyn component services . . . \n"

	printf "\nAbout Client service 		\n"
	if [ ! -z "$(ps | grep "AboutClient" | awk '{print $1}')" ];then
		printf "Service Stopping. . .			"
		kill -9 $(ps | grep "AboutClient" | awk '{print $1}')
		printf "Done\n"
		printf "Service Starting. . . 			"
		$path/core/alljoyn/core/alljoyn/build/linux/$TARGET_CPU/debug/dist/about/bin/AboutClient >> $path/logs/alljoyn/AboutClient.log 2>&1 &
		printf "Done\n"
	else
		printf "Service Starting. . .                   "
                $path/core/alljoyn/core/alljoyn/build/linux/$TARGET_CPU/debug/dist/about/bin/AboutClient >> $path/logs/alljoyn/AboutClient.log 2>&1 &
                printf "Done\n"
	fi

	printf "\nNotification Consumer service	\n"
	if [ ! -z "$(ps | grep "ConsumerService" | awk '{print $1}')" ];then
		printf "Service Stopping. . .			"
		kill -9 $(ps | grep "ConsumerService" | awk '{print $1}')
		printf "Done\n"
		printf "Service Starting. . . 			"
		$path/core/alljoyn/core/alljoyn/build/linux/$TARGET_CPU/debug/dist/notification/bin/ConsumerService >> $path/logs/alljoyn/ConsumerService.log 2>&1 &
		printf "Done\n"
	else
		printf "Service Starting. . .                   "
		$path/core/alljoyn/core/alljoyn/build/linux/$TARGET_CPU/debug/dist/notification/bin/ConsumerService >> $path/logs/alljoyn/ConsumerService.log 2>&1 &
                printf "Done\n"
	fi

#	printf "\nOnboarding Client service	\n"
#	if [ ! -z "$(ps | grep "OnboardingClien" | awk '{print $1}')" ];then
#		printf "Service Stopping. . .			"
#		kill -9 $(ps | grep "OnboardingClien" | awk '{print $1}')
#		printf "Done\n"
#		printf "Service Starting. . . 			"
#		$path/core/alljoyn/core/alljoyn/build/linux/$TARGET_CPU/debug/dist/onboarding/bin/OnboardingClient >> $path/logs/alljoyn/OnboardingClient.log 2>&1 &
#		printf "Done\n"
#	else
#		printf "Service Starting. . .                   "
#		$path/core/alljoyn/core/alljoyn/build/linux/$TARGET_CPU/debug/dist/onboarding/bin/OnboardingClient >> $path/logs/alljoyn/OnboardingClient.log 2>&1 &
#                printf "Done\n"
#	fi

#	printf "\nOnboarding Daemon service	\n"
#	if [ ! -z "$(ps | grep "onboardingdaemo" | awk '{print $1}')" ];then
#		printf "Service Stopping. . .			"
#		kill -9 $(ps | grep "onboardingdaemo" | awk '{print $1}')
#		printf "Done\n"
#		printf "Service Starting. . . 			"
#		$path/core/alljoyn/core/alljoyn/build/linux/$TARGET_CPU/debug/dist/onboarding/bin/onboardingdaemon >> $path/logs/alljoyn/onboardingdaemon.log 2>&1 &
#		printf "Done\n"
#	else
#		printf "Service Starting. . .                   "
#		$path/core/alljoyn/core/alljoyn/build/linux/$TARGET_CPU/debug/dist/onboarding/bin/onboardingdaemon >> $path/logs/alljoyn/onboardingdaemon.log 2>&1 &
#                printf "Done\n"
#	fi

	printf "\nControl Panel service	\n"
	if [ ! -z "$(ps | grep "ControlPanelCon" | awk '{print $1}')" ];then
		printf "Service Stopping. . .			"
		kill -9 $(ps | grep "ControlPanelCon" | awk '{print $1}')
		printf "Done\n"
		printf "Service Starting. . . 			"
		$path/core/alljoyn/core/alljoyn/build/linux/$TARGET_CPU/debug/dist/controlpanel/bin/ControlPanelController >> $path/logs/alljoyn/ControlPanelController.log 2>&1 &
		printf "Done\n"
	else
		printf "Service Starting. . .                   "
		$path/core/alljoyn/core/alljoyn/build/linux/$TARGET_CPU/debug/dist/controlpanel/bin/ControlPanelController >> $path/logs/alljoyn/ControlPanelController.log 2>&1 &
                printf "Done\n"
	fi

#	printf "Notification Producer service . . .	"
#	$path/core/alljoyn/core/alljoyn/build/linux/$TARGET_CPU/debug/dist/notification/bin/ProducerService >> $path/logs/alljoyn/ProducerService.log  2>&1 &
#	printf "Done\n\n"
	printf "\nAlljoyn component services restarted Successfully.!\n"
	
elif [ $arg == 'stop' ]; then
	printf "Stoping Alljoyn component services . . . \n"	

	printf "\nAbout Client service\n"
	if [ -z $(ps | grep "AboutClient" | awk '{print $1}') ];then
		printf "Service found not running . . .\n"
	else
		printf "Service stopping. . .			"
		kill -9 $(ps | grep "AboutClient" | awk '{print $1}')
		printf "Done\n"
	fi

	printf "\nNotification Consumer Service\n"
	if [ -z $(ps | grep "ConsumerService" | awk '{print $1}') ];then
		printf "Service found not running . . .\n"
	else
		printf "Service stopping. . .			"
		kill -9 $(ps | grep "ConsumerService" | awk '{print $1}')
		printf "Done\n"
	fi

#	printf "\nOnboarding Client service\n"
#	if [ -z $(ps | grep "OnboardingClien" | awk '{print $1}') ];then
#		printf "Service found not running . . .\n"
#	else
#		printf "Service stopping. . .			"
#		kill -9 $(ps | grep "OnboardingClien" | awk '{print $1}')
#		printf "Done\n"
#	fi

#	printf "\nOnboarding Daemon service\n"
#	if [ -z $(ps | grep "onboardingdaemo" | awk '{print $1}') ];then
#		printf "Service found not running . . .\n"
#	else
#		printf "Service stopping. . .			"
#		kill -9 $(ps | grep "onboardingdaemo" | awk '{print $1}')
#		printf "Done\n"
#	fi

	printf "\nControl Panel Service\n"
	if [ -z $(ps | grep "ControlPanelCon" | awk '{print $1}') ];then
		printf "Service found not running . . .\n"
	else
		printf "Service stopping. . .			"
		kill -9 $(ps | grep "ControlPanelCon" | awk '{print $1}')
		printf "Done\n"
	fi

#	printf "Notification Producer Service. . . 	"
#	kill -9 $(ps | grep "ProducerService" | awk '{print $1}')
#	printf "Done\n\n"
	printf "\nAlljoyn component services stop successfully.!\n"
elif [ $arg == "status" ];then
        printf "\nAbout Client service\n"
        if [ -z $(ps | grep "AboutClient" | awk '{print $1}') ];then
                printf "Service found not running . . .\n"
        else
                printf "Service is running . . .\n"
        fi

        printf "\nNotification Consumer Service\n"
        if [ -z $(ps | grep "ConsumerService" | awk '{print $1}') ];then
                printf "Service found not running . . .\n"
        else
                printf "Service is running . . .\n"
        fi

#        printf "\nOnboarding Client service\n"
#        if [ -z $(ps | grep "OnboardingClien" | awk '{print $1}') ];then
#                printf "Service found not running . . .\n"
#        else
#                printf "Service is running . . .\n"
#        fi

#        printf "\nOnboarding Daemon service\n"
#        if [ -z $(ps | grep "onboardingdaemo" | awk '{print $1}') ];then
#                printf "Service found not running . . .\n"
#        else
#                printf "Service is running . . .\n"
#        fi

        printf "\nControl Panel Service\n"
        if [ -z $(ps | grep "ControlPanelCon" | awk '{print $1}') ];then
                printf "Service found not running . . .\n"
        else
                printf "Service is running . . .\n"
        fi

	printf "\n"
else
	printf "USAGE: ./run.sh {start/stop/status/restart}\n"
fi
