#!/bin/bash

# This setup.sh script installs necessary dependencies for 'Unified IoT Dashboard' Framework
# to be worked properly on this machine.

# Setup for Alljoyn
sudo apt-get update
sudo apt-get install build-essential gcc g++ libssl-dev python scons libcurl-dev apache2 php5 mysql-server libapache2-mod-php5 libxml2-dev libmysql++-dev -y

# Logs for alljoyn component services
mkdir -p logs/alljoyn

# Assuming apache2 home directory set to '/var/www' or '/var/www/html'
if [ -d '/var/www/html' ]; then
	sudo ln -s `pwd` /var/www/html 
else
	sudo ln -s `pwd` /var/www
fi
