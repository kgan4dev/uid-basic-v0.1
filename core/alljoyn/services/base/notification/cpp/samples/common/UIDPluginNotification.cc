#include "UIDPluginNotification.h"
#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

UIDUtils::UIDUtils() {
}

UIDUtils::~UIDUtils() {
}

void UIDUtils::setAJDeviceNotificationField(string key, string value) 
{
	if (!key.compare("MessageId")) {
		myAJDeviceNotification.MessageId = value;
	} else if (!key.compare("DeviceId")) {
		myAJDeviceNotification.DeviceId = value;
	} else if (!key.compare("DeviceName")) {
		myAJDeviceNotification.DeviceName = value;
	} else if (!key.compare("AppId")) {
		myAJDeviceNotification.AppId = value;
	} else if (!key.compare("AppName")) {
		myAJDeviceNotification.AppName = value;
	} else if (!key.compare("SenderBusName")) {
		myAJDeviceNotification.SenderBusName = value;
	} else if (!key.compare("MessageType")) {
		myAJDeviceNotification.MessageType = value;
	} else if (!key.compare("Version")) {
		myAJDeviceNotification.Version = value;
	} else if (!key.compare("Language")) {
		myAJDeviceNotification.Language = value;
	} else if (!key.compare("Message")) {
		myAJDeviceNotification.Message = value;
	} else if (!key.compare("Status")) {
		myAJDeviceNotification.Status = value;
	} else {
		cerr << "UIDUtils::setAJDeviceNotificationField Invalid call" << endl;
	}
}

string UIDUtils::getAJDeviceNotificationField(string key)
{
        if (!key.compare("MessageId")) {
                return myAJDeviceNotification.MessageId;
        } else if (!key.compare("DeviceId")) {
                return myAJDeviceNotification.DeviceId;
        } else if (!key.compare("DeviceName")) {
                return myAJDeviceNotification.DeviceName;
        } else if (!key.compare("AppId")) {
                return myAJDeviceNotification.AppId;
        } else if (!key.compare("AppName")) {
                return myAJDeviceNotification.AppName;
        } else if (!key.compare("SenderBusName")) {
                return myAJDeviceNotification.SenderBusName;
        } else if (!key.compare("MessageType")) {
                return myAJDeviceNotification.MessageType;
        } else if (!key.compare("Version")) {
                return myAJDeviceNotification.Version;
        } else if (!key.compare("Language")) {
                return myAJDeviceNotification.Language;
        } else if (!key.compare("Message")) {
                return myAJDeviceNotification.Message;
        } else if (!key.compare("Status")) {
                return myAJDeviceNotification.Status;
        } else {
                cerr << "UIDUtils::getAJDeviceNotificationField Invalid call" << endl;
        }
}

void UIDUtils::insertAJDeviceNotificationToDb () {
	string hostname = "localhost";
	string username = "root";
	string password = "vedams";

	MYSQL *conn;

	string createTable = "CREATE TABLE IF NOT EXISTS UIDTestNotification (\
MessageId VARCHAR(20) NOT NULL,\
DeviceId VARCHAR(20) NOT NULL,\
DeviceName VARCHAR(20) NOT NULL,\
AppId VARCHAR(20) NOT NULL,\
AppName VARCHAR(20) NOT NULL,\
SenderBusName VARCHAR(15) NOT NULL,\
MessageType VARCHAR(10) NOT NULL,\
Version VARCHAR(5) NOT NULL,\
Language VARCHAR(5) NOT NULL,\
Message VARCHAR(100) NOT NULL,\
Status VARCHAR(10) NOT NULL)";

	string insertTable = "INSERT INTO UIDTestNotification (MessageId, DeviceId,\
DeviceName, AppId, AppName, SenderBusName, MessageType, Version, Language, Message, Status )\
VALUES ( '" + myAJDeviceNotification.MessageId + "','" + myAJDeviceNotification.DeviceId + "','\
" + myAJDeviceNotification.DeviceName + "','" + myAJDeviceNotification.AppId + "','\
" + myAJDeviceNotification.AppName + "','" + myAJDeviceNotification.SenderBusName + "','\
" + myAJDeviceNotification.MessageType + "','" + myAJDeviceNotification.Version + "','\
" + myAJDeviceNotification.Language + "','" + myAJDeviceNotification.Message +  "','\
" + myAJDeviceNotification.Status + "')";

	if ( (conn = mysql_init(NULL)) == NULL ) {
		cerr << "MYSQL ERROR : " <<  mysql_error(conn)  << endl;
		exit(0);
	}

	if (mysql_real_connect(conn, hostname.c_str(), username.c_str(), password.c_str(), NULL, 0, NULL, 0) == NULL) {
		cerr << "MYSQL ERROR : " <<  mysql_error(conn)  << endl;
		exit(0);
	}

	if (mysql_query(conn, "CREATE DATABASE IF NOT EXISTS UIDTest")) {
		cerr << "MYSQL ERROR : " <<  mysql_error(conn)  << endl;
		exit(0);
	}

	if (mysql_query(conn, "use UIDTest")) {
		cerr << "MYSQL ERROR : " <<  mysql_error(conn)  << endl;
		exit(0);
	}

	if (mysql_query(conn, createTable.c_str())) {
		cerr << "MYSQL ERROR : " <<  mysql_error(conn)  << endl;
		exit(0);
	}

	if (mysql_query(conn, insertTable.c_str())) {
		cerr << "MYSQL ERROR : " <<  mysql_error(conn)  << endl;
		exit(0);
	}

	mysql_close(conn);
}
