#include "UIDPluginCPController.h"
#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

UIDUtils::UIDUtils() {
}

UIDUtils::~UIDUtils() {
}

int NoOfDevices;

void UIDUtils::setAJDeviceCPDialogWidgetField(string key, string value) 
{
	if (!key.compare("name")) {
		myAJDeviceCPDialogWidget.name = value;
	} else if (!key.compare("version")) {
		myAJDeviceCPDialogWidget.version = value;
	} else if (!key.compare("secured")) {
		myAJDeviceCPDialogWidget.secured = value;
	} else if (!key.compare("enabled")) {
		myAJDeviceCPDialogWidget.enabled = value;
	} else if (!key.compare("label")) {
		myAJDeviceCPDialogWidget.label = value;
	} else if (!key.compare("bgColor")) {
		myAJDeviceCPDialogWidget.bgColor = value;
	} else if (!key.compare("hints")) {
		myAJDeviceCPDialogWidget.hints = value;
	} else if (!key.compare("message")) {
		myAJDeviceCPDialogWidget.message = value;
	} else if (!key.compare("numActions")) {
		myAJDeviceCPDialogWidget.numActions = value;
	} else if (!key.compare("LabelforAction1")) {
		myAJDeviceCPDialogWidget.LabelforAction1 = value;
	} else if (!key.compare("LabelforAction2")) {
		myAJDeviceCPDialogWidget.LabelforAction2 = value;
	} else if (!key.compare("LabelforAction3")) {
		myAJDeviceCPDialogWidget.LabelforAction3 = value;
	} else {
		cerr << "UIDUtils::setAJDeviceCPDialogWidgetField Invalid call" << endl;
	}
}

string UIDUtils::getAJDeviceCPDialogWidgetField(string key)
{
        if (!key.compare("name")) {
                return myAJDeviceCPDialogWidget.name;
        } else if (!key.compare("version")) {
                return myAJDeviceCPDialogWidget.version;
        } else if (!key.compare("secured")) {
                return myAJDeviceCPDialogWidget.secured;
        } else if (!key.compare("enabled")) {
                return myAJDeviceCPDialogWidget.enabled;
        } else if (!key.compare("label")) {
                return myAJDeviceCPDialogWidget.label;
        } else if (!key.compare("bgColor")) {
                return myAJDeviceCPDialogWidget.bgColor;
        } else if (!key.compare("hints")) {
                return myAJDeviceCPDialogWidget.hints;
        } else if (!key.compare("message")) {
                return myAJDeviceCPDialogWidget.message;
        } else if (!key.compare("numActions")) {
                return myAJDeviceCPDialogWidget.numActions;
        } else if (!key.compare("LabelforAction1")) {
                return myAJDeviceCPDialogWidget.LabelforAction1;
        } else if (!key.compare("LabelforAction2")) {
                return myAJDeviceCPDialogWidget.LabelforAction2;
        } else if (!key.compare("LabelforAction3")) {
                return myAJDeviceCPDialogWidget.LabelforAction3;
        } else {
                cerr << "UIDUtils::getAJDeviceCPDialogWidgetField Invalid call" << endl;
        }
}

void UIDUtils::insertAJDeviceCPDialogWidgetToDb () {
	string hostname = "localhost";
	string username = "root";
	string password = "vedams";

	MYSQL *conn;

	string createTable = "CREATE TABLE IF NOT EXISTS UIDTestDialogWidget (\
name VARCHAR(30) NOT NULL,\
version VARCHAR(30) NOT NULL,\
secured VARCHAR(30) NOT NULL,\
enabled VARCHAR(30) NOT NULL,\
label VARCHAR(30) NOT NULL,\
bgColor VARCHAR(30) NOT NULL,\
hints VARCHAR(30) NOT NULL,\
message VARCHAR(30) NOT NULL,\
numActions VARCHAR(30) NOT NULL,\
LabelforAction1 VARCHAR(30) NOT NULL,\
LabelforAction2 VARCHAR(30) NOT NULL,\
LabelforAction3 VARCHAR(30) NOT NULL)";

	string insertTable = "INSERT INTO UIDTestDialogWidget (name, version,\
secured, enabled, label, bgColor, hints, message, numActions, LabelforAction1, LabelforAction2, LabelforAction3 )\
VALUES ( '" + myAJDeviceCPDialogWidget.name + "','" + myAJDeviceCPDialogWidget.version + "','\
" + myAJDeviceCPDialogWidget.secured + "','" + myAJDeviceCPDialogWidget.enabled + "','\
" + myAJDeviceCPDialogWidget.label + "','" + myAJDeviceCPDialogWidget.bgColor + "','\
" + myAJDeviceCPDialogWidget.hints + "','" + myAJDeviceCPDialogWidget.message + "','\
" + myAJDeviceCPDialogWidget.numActions + "','" + myAJDeviceCPDialogWidget.LabelforAction1 +  "','\
" + myAJDeviceCPDialogWidget.LabelforAction2 + "','" + myAJDeviceCPDialogWidget.LabelforAction3 + "')";

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


void UIDUtils::setAJDeviceCPActionWidgetField(string key, string value) 
{
	if (!key.compare("name")) {
		myAJDeviceCPActionWidget.name = value;
	} else if (!key.compare("version")) {
		myAJDeviceCPActionWidget.version = value;
	} else if (!key.compare("secured")) {
		myAJDeviceCPActionWidget.secured = value;
	} else if (!key.compare("enabled")) {
		myAJDeviceCPActionWidget.enabled = value;
	} else if (!key.compare("label")) {
		myAJDeviceCPActionWidget.label = value;
	} else if (!key.compare("bgColor")) {
		myAJDeviceCPActionWidget.bgColor = value;
	} else if (!key.compare("hints")) {
		myAJDeviceCPActionWidget.hints = value;
	} else if (!key.compare("ChildDialog")) {
		myAJDeviceCPActionWidget.ChildDialog = value;
	} else if (!key.compare("ChildName")) {
		myAJDeviceCPActionWidget.ChildName = value;
	} else {
		cerr << "UIDUtils::setAJDeviceCPActionWidgetField Invalid call" << endl;
	}
}

string UIDUtils::getAJDeviceCPActionWidgetField(string key)
{
        if (!key.compare("name")) {
                return myAJDeviceCPActionWidget.name;
        } else if (!key.compare("version")) {
                return myAJDeviceCPActionWidget.version;
        } else if (!key.compare("secured")) {
                return myAJDeviceCPActionWidget.secured;
        } else if (!key.compare("enabled")) {
                return myAJDeviceCPActionWidget.enabled;
        } else if (!key.compare("label")) {
                return myAJDeviceCPActionWidget.label;
        } else if (!key.compare("bgColor")) {
                return myAJDeviceCPActionWidget.bgColor;
        } else if (!key.compare("hints")) {
                return myAJDeviceCPActionWidget.hints;
        } else if (!key.compare("ChildDialog")) {
                return myAJDeviceCPActionWidget.ChildDialog;
        } else if (!key.compare("ChildName")) {
                return myAJDeviceCPActionWidget.ChildName;
        } else {
                cerr << "UIDUtils::getAJDeviceCPActionWidgetField Invalid call" << endl;
        }
}

void UIDUtils::insertAJDeviceCPActionWidgetToDb () {
	string hostname = "localhost";
	string username = "root";
	string password = "vedams";

	MYSQL *conn;

	string createTable = "CREATE TABLE IF NOT EXISTS UIDTestActionWidget (\
name VARCHAR(30) NOT NULL,\
version VARCHAR(30) NOT NULL,\
secured VARCHAR(30) NOT NULL,\
enabled VARCHAR(30) NOT NULL,\
label VARCHAR(30) NOT NULL,\
bgColor VARCHAR(100) NOT NULL,\
hints VARCHAR(30) NOT NULL,\
ChildDialog VARCHAR(30) NOT NULL,\
ChildName VARCHAR(30) NOT NULL)";

	string insertTable = "INSERT INTO UIDTestActionWidget (name, version,\
secured, enabled, label, bgColor, hints, ChildDialog, ChildName )\
VALUES ( '" + myAJDeviceCPActionWidget.name + "','" + myAJDeviceCPActionWidget.version + "','\
" + myAJDeviceCPActionWidget.secured + "','" + myAJDeviceCPActionWidget.enabled + "','\
" + myAJDeviceCPActionWidget.label + "','" + myAJDeviceCPActionWidget.bgColor + "','\
" + myAJDeviceCPActionWidget.hints + "','" + myAJDeviceCPActionWidget.ChildDialog + "','\
" + myAJDeviceCPActionWidget.ChildName + "')";

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
