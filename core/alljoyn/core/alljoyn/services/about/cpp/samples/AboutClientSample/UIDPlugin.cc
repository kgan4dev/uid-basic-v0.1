#include "UIDPlugin.h"
#include <stdlib.h>
#include <string.h>
#include <iostream>

using namespace std;

UIDUtils::UIDUtils() {
}

UIDUtils::~UIDUtils() {
}

void UIDUtils::updateAJDeviceBusStatusToDb (AJDeviceProfile *myAJDeviceProfile) {
        string hostname = "localhost";
        string username = "root";
        string password = "vedams";

	MYSQL *conn;

        string updateTable = "UPDATE UIDTestTable SET BusName='" + myAJDeviceProfile->BusName + "',\
Status='" + myAJDeviceProfile->Status + "' WHERE DeviceName='" + myAJDeviceProfile->DeviceName + "'";

        if ( (conn = mysql_init(NULL)) == NULL ) {
                cerr << "MYSQL ERROR : " <<  mysql_error(conn)  << endl;
                exit(0);
        }

        if (mysql_real_connect(conn, hostname.c_str(), username.c_str(), password.c_str(), NULL, 0, NULL, 0) == NULL) {
                cerr << "MYSQL ERROR : " <<  mysql_error(conn)  << endl;
                exit(0);
        }

        if (mysql_query(conn, "use UIDTest")) {
                cerr << "MYSQL ERROR : " <<  mysql_error(conn)  << endl;
                exit(0);
        }

        if (mysql_query(conn, updateTable.c_str())) {
                cerr << "MYSQL ERROR : " <<  mysql_error(conn)  << endl;
                exit(0);
        }
	
        mysql_close(conn);
}

void UIDUtils::insertAJDeviceProfileToDb (AJDeviceProfile *myAJDeviceProfile) {
	string hostname = "localhost";
	string username = "root";
	string password = "vedams";

	MYSQL *conn;

	string createTable = "CREATE TABLE IF NOT EXISTS UIDTestTable (\
AJSoftwareVersion VARCHAR(30) NOT NULL,\
AppId VARCHAR(30) NOT NULL,\
AppName VARCHAR(30) NOT NULL,\
DateOfManufacture VARCHAR(30) NOT NULL,\
DefaultLanguage VARCHAR(5) NOT NULL,\
Description VARCHAR(100) NOT NULL,\
DeviceId VARCHAR(30) NOT NULL,\
DeviceName VARCHAR(30) NOT NULL,\
HardwareVersion VARCHAR(30) NOT NULL,\
Manufacturer VARCHAR(30) NOT NULL,\
ModelNumber VARCHAR(30) NOT NULL,\
SoftwareVersion VARCHAR(30) NOT NULL,\
SupportUrl VARCHAR(30) NOT NULL,\
SupportedLanguages VARCHAR(30) NOT NULL,\
BusName VARCHAR(30) NOT NULL,\
Status VARCHAR(30) NOT NULL)";

	string insertTable = "INSERT INTO UIDTestTable (AJSoftwareVersion, AppId,\
AppName,DateOfManufacture, DefaultLanguage,Description, DeviceId, DeviceName, HardwareVersion,\
Manufacturer,ModelNumber, SoftwareVersion, SupportUrl, SupportedLanguages, BusName, Status )\
VALUES ( '" + myAJDeviceProfile->AJSoftwareVersion + "','" + myAJDeviceProfile->AppId + "','\
" + myAJDeviceProfile->AppName + "','" + myAJDeviceProfile->DateOfManufacture + "','\
" + myAJDeviceProfile->DefaultLanguage + "','" + myAJDeviceProfile->Description + "','\
" + myAJDeviceProfile->DeviceId + "','" + myAJDeviceProfile->DeviceName + "','\
" + myAJDeviceProfile->HardwareVersion + "','" + myAJDeviceProfile->Manufacturer + "','\
" + myAJDeviceProfile->ModelNumber + "','" + myAJDeviceProfile->SoftwareVersion + "','\
" + myAJDeviceProfile->SupportUrl + "','" + myAJDeviceProfile->SupportedLanguages + "','\
" + myAJDeviceProfile->BusName + "','" + myAJDeviceProfile->Status + "')";

        string updateTable = "UPDATE UIDTestTable SET BusName='" + myAJDeviceProfile->BusName + "',\
Status='" + myAJDeviceProfile->Status + "' WHERE DeviceName='" + myAJDeviceProfile->DeviceName + "'";

	string searchTable = "SELECT * FROM UIDTestTable WHERE DeviceName='" + myAJDeviceProfile->DeviceName + "'";;

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

	if (mysql_query(conn, searchTable.c_str())) {
		cerr << "MYSQL ERROR : " <<  mysql_error(conn)  << endl;
		exit(0);
	}

	MYSQL_RES *result = mysql_store_result(conn);

	if(result == NULL) {
		cerr << "MYSQL ERROR : " <<  mysql_error(conn)  << endl;
		exit(0);
	}

	int num_fields = mysql_num_fields(result);

	MYSQL_ROW row;

	if(!(row = mysql_fetch_row(result))) {
		if (mysql_query(conn, insertTable.c_str())) {
			cerr << "MYSQL ERROR : " <<  mysql_error(conn)  << endl;
			exit(0);
		}
	} else {
		string temp = (string)row[7];
		if(!temp.compare(myAJDeviceProfile->DeviceName)) {
		        if (mysql_query(conn, updateTable.c_str())) {
		                cerr << "MYSQL ERROR : " <<  mysql_error(conn)  << endl;
		                exit(0);
		        }
		} else {
			if (mysql_query(conn, insertTable.c_str())) {
				cerr << "MYSQL ERROR : " <<  mysql_error(conn)  << endl;
				exit(0);
			}
		}		
	}
  
	mysql_free_result(result);

	mysql_close(conn);
}

void UIDUtils::setAJDeviceProfileField(AJDeviceProfile *myAJDeviceProfile,string key,string value) {
	if (!key.compare("AJSoftwareVersion")) {
		myAJDeviceProfile->AJSoftwareVersion = value;
	} else if (!key.compare("AppId")) {
		myAJDeviceProfile->AppId = value;
	} else if (!key.compare("AppName")) {
		myAJDeviceProfile->AppName = value;
	} else if (!key.compare("DateOfManufacture")) {
		myAJDeviceProfile->DateOfManufacture = value;
	} else if (!key.compare("DefaultLanguage")) {
		myAJDeviceProfile->DefaultLanguage = value;
	} else if (!key.compare("Description")) {
		myAJDeviceProfile->Description = value;
	} else if (!key.compare("DeviceId")) {
		myAJDeviceProfile->DeviceId = value;
	} else if (!key.compare("DeviceName")) {
		myAJDeviceProfile->DeviceName = value;
	} else if (!key.compare("HardwareVersion")) {
		myAJDeviceProfile->HardwareVersion = value;
	} else if (!key.compare("Manufacturer")) {
		myAJDeviceProfile->Manufacturer = value;
	} else if (!key.compare("ModelNumber")) {
		myAJDeviceProfile->ModelNumber = value;
	} else if (!key.compare("SoftwareVersion")) {
		myAJDeviceProfile->SoftwareVersion = value;
	} else if (!key.compare("SupportUrl")) {
		myAJDeviceProfile->SupportUrl = value;
	} else if (!key.compare("SupportedLanguages")) {
		myAJDeviceProfile->SupportedLanguages = value;
	} else if (!key.compare("BusName")) {
		myAJDeviceProfile->BusName = value;
	} else if (!key.compare("Status")) {
		myAJDeviceProfile->Status = value;
	} else {
		cerr << "UIDUtils::setAJDeviceProfileField Invalid call" << endl;
	}
}
