#include "UIDPluginNotification.h"
#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

UIDUtils::UIDUtils() {
}

UIDUtils::~UIDUtils() {
}

int NoOfDevices;

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
DeviceName VARCHAR(15) NOT NULL,\
AppId VARCHAR(20) NOT NULL,\
AppName VARCHAR(15) NOT NULL,\
SenderBusName VARCHAR(10) NOT NULL,\
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

void UIDUtils::DeviceToCheckStatus ()
{
        string hostname = "localhost";
        string username = "root";
        string password = "vedams";

        MYSQL *conn;
	MYSQL_RES *result;
	MYSQL_ROW row;

        string searchTable = "SELECT * FROM UIDTestTable";	
	string countTableRows = "SELECT COUNT(*) FROM UIDTestTable";

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

	if ( NoOfDevices == 0 ) {
	        if (mysql_query(conn,countTableRows.c_str())) {
        	        cerr << "MYSQL ERROR : " <<  mysql_error(conn)  << endl;
                	exit(0);
		}

		result = mysql_store_result(conn);
	
		if(result == NULL) {
			cerr << "MYSQL ERROR : " <<  mysql_error(conn)  << endl;
			exit(0);
		}

		row =  mysql_fetch_row(result);

		/* Number of Devices registered in Database */
		NoOfDevices = atoi(row[0]);

//		cout << " NoOfDevices in Database : " << NoOfDevices << endl; 

		mysql_free_result(result);
	}

        if (mysql_query(conn, searchTable.c_str())) {
                cerr << "MYSQL ERROR : " <<  mysql_error(conn)  << endl;
                exit(0);
	}

	result = mysql_store_result(conn);

	if(result == NULL) {
		cerr << "MYSQL ERROR : " <<  mysql_error(conn)  << endl;
		exit(0);
	}

	int temp = NoOfDevices;

	while((row =  mysql_fetch_row(result))) {
		if ( --temp ) { 
			continue;
		} else {
			myAJDeviceProfile.AJSoftwareVersion = (string) row[0]; 
			myAJDeviceProfile.AppId = (string) row[1];
			myAJDeviceProfile.AppName = (string) row[2];
			myAJDeviceProfile.DateOfManufacture = (string) row[3];
			myAJDeviceProfile.DefaultLanguage = (string) row[4];
			myAJDeviceProfile.Description = (string) row[5];
			myAJDeviceProfile.DeviceId = (string) row[6];
			myAJDeviceProfile.DeviceName = (string) row[7];
			myAJDeviceProfile.HardwareVersion = (string) row[8];
			myAJDeviceProfile.Manufacturer = (string) row[9];
			myAJDeviceProfile.ModelNumber = (string) row[10];
			myAJDeviceProfile.SoftwareVersion = (string) row[11];
			myAJDeviceProfile.SupportUrl = (string) row[12];
			myAJDeviceProfile.SupportedLanguages = (string) row[13];
			myAJDeviceProfile.BusName = (string) row[14];
			myAJDeviceProfile.Status = (string) row[15];
		}
	}
  
	--NoOfDevices;

	mysql_free_result(result);
  
        mysql_close(conn);
}

void UIDUtils::updateAJDeviceBusStatusToDb () 
{
        string hostname = "localhost";
        string username = "root";
        string password = "vedams";

	MYSQL *conn;

        string updateTable = "UPDATE UIDTestTable SET BusName='" + myAJDeviceProfile.BusName + "',\
Status='" + myAJDeviceProfile.Status + "' WHERE DeviceName='" + myAJDeviceProfile.DeviceName + "'";

	string searchTable = "SELECT * FROM UIDTestTable WHERE DeviceName='" + myAJDeviceProfile.DeviceName + "'";

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
	
	if (mysql_query(conn, searchTable.c_str())) {
		cerr << "MYSQL ERROR : " <<  mysql_error(conn)  << endl;
		exit(0);
	}

	MYSQL_RES *result = mysql_store_result(conn);

	if(result == NULL) {
		cerr << "MYSQL ERROR : " <<  mysql_error(conn)  << endl;
		exit(0);
	}

	MYSQL_ROW row;

	if(!(row = mysql_fetch_row(result))) {
		cerr << "MYSQL ERROR : Empty Table cannot update"  << endl;
//		exit(0);
	} else {
		string temp = (string)row[7];
		if(!temp.compare(myAJDeviceProfile.DeviceName)) {
			/* Update the status of Device Bus */
		        if (mysql_query(conn, updateTable.c_str())) {
		       	        cerr << "MYSQL ERROR : " <<  mysql_error(conn)  << endl;
		               	exit(0);
		        }
		}
	}
  
	mysql_free_result(result);
  
        mysql_close(conn);
}

void UIDUtils::insertAJDeviceProfileToDb () {
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
VALUES ( '" + myAJDeviceProfile.AJSoftwareVersion + "','" + myAJDeviceProfile.AppId + "','\
" + myAJDeviceProfile.AppName + "','" + myAJDeviceProfile.DateOfManufacture + "','\
" + myAJDeviceProfile.DefaultLanguage + "','" + myAJDeviceProfile.Description + "','\
" + myAJDeviceProfile.DeviceId + "','" + myAJDeviceProfile.DeviceName + "','\
" + myAJDeviceProfile.HardwareVersion + "','" + myAJDeviceProfile.Manufacturer + "','\
" + myAJDeviceProfile.ModelNumber + "','" + myAJDeviceProfile.SoftwareVersion + "','\
" + myAJDeviceProfile.SupportUrl + "','" + myAJDeviceProfile.SupportedLanguages + "','\
" + myAJDeviceProfile.BusName + "','" + myAJDeviceProfile.Status + "')";

        string updateTable = "UPDATE UIDTestTable SET BusName='" + myAJDeviceProfile.BusName + "',\
Status='" + myAJDeviceProfile.Status + "' WHERE DeviceName='" + myAJDeviceProfile.DeviceName + "'";

	string searchTable = "SELECT * FROM UIDTestTable WHERE DeviceName='" + myAJDeviceProfile.DeviceName + "'";;

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

	MYSQL_ROW row;

	/* If Table is empty, Insert new table*/
	if(!(row = mysql_fetch_row(result))) {
		if (mysql_query(conn, insertTable.c_str())) {
			cerr << "MYSQL ERROR : " <<  mysql_error(conn)  << endl;
			exit(0);
		}
	} else {
		do {
			string temp = (string)row[7];
			if(!temp.compare(myAJDeviceProfile.DeviceName)) {
				/* If Device already exists, Change busName to new */
			        if (mysql_query(conn, updateTable.c_str())) {
		        	        cerr << "MYSQL ERROR : " <<  mysql_error(conn)  << endl;
		                	exit(0);
			        }
			} else {
				/* If Device not exists, insert new table */
				if (mysql_query(conn, insertTable.c_str())) {
					cerr << "MYSQL ERROR : " <<  mysql_error(conn)  << endl;
					exit(0);
				}
			}		
		}while((row = mysql_fetch_row(result)));
	}

	mysql_free_result(result);

	mysql_close(conn);
}

string UIDUtils::getAJDeviceProfileField(string key) {
	if (!key.compare("AJSoftwareVersion")) {
		return myAJDeviceProfile.AJSoftwareVersion;
	} else if (!key.compare("AppId")) {
		return myAJDeviceProfile.AppId;
	} else if (!key.compare("AppName")) {
		return myAJDeviceProfile.AppName;
	} else if (!key.compare("DateOfManufacture")) {
		return myAJDeviceProfile.DateOfManufacture;
	} else if (!key.compare("DefaultLanguage")) {
		return myAJDeviceProfile.DefaultLanguage;
	} else if (!key.compare("Description")) {
		return myAJDeviceProfile.Description;
	} else if (!key.compare("DeviceId")) {
		return myAJDeviceProfile.DeviceId;
	} else if (!key.compare("DeviceName")) {
		return myAJDeviceProfile.DeviceName;
	} else if (!key.compare("HardwareVersion")) {
		return myAJDeviceProfile.HardwareVersion;
	} else if (!key.compare("Manufacturer")) {
		return myAJDeviceProfile.Manufacturer;
	} else if (!key.compare("ModelNumber")) {
		return myAJDeviceProfile.ModelNumber;
	} else if (!key.compare("SoftwareVersion")) {
		return myAJDeviceProfile.SoftwareVersion;
	} else if (!key.compare("SupportUrl")) {
		return myAJDeviceProfile.SupportUrl;
	} else if (!key.compare("SupportedLanguages")) {
		return myAJDeviceProfile.SupportedLanguages;
	} else if (!key.compare("BusName")) {
		return myAJDeviceProfile.BusName;
	} else if (!key.compare("Status")) {
		return myAJDeviceProfile.Status;
	} else {
		cerr << "UIDUtils::getAJDeviceProfileField Invalid call" << endl;
		return "Invalid call";
	}
}

void UIDUtils::setAJDeviceProfileField(string key,string value) {
	if (!key.compare("AJSoftwareVersion")) {
		myAJDeviceProfile.AJSoftwareVersion = value;
	} else if (!key.compare("AppId")) {
		myAJDeviceProfile.AppId = value;
	} else if (!key.compare("AppName")) {
		myAJDeviceProfile.AppName = value;
	} else if (!key.compare("DateOfManufacture")) {
		myAJDeviceProfile.DateOfManufacture = value;
	} else if (!key.compare("DefaultLanguage")) {
		myAJDeviceProfile.DefaultLanguage = value;
	} else if (!key.compare("Description")) {
		myAJDeviceProfile.Description = value;
	} else if (!key.compare("DeviceId")) {
		myAJDeviceProfile.DeviceId = value;
	} else if (!key.compare("DeviceName")) {
		myAJDeviceProfile.DeviceName = value;
	} else if (!key.compare("HardwareVersion")) {
		myAJDeviceProfile.HardwareVersion = value;
	} else if (!key.compare("Manufacturer")) {
		myAJDeviceProfile.Manufacturer = value;
	} else if (!key.compare("ModelNumber")) {
		myAJDeviceProfile.ModelNumber = value;
	} else if (!key.compare("SoftwareVersion")) {
		myAJDeviceProfile.SoftwareVersion = value;
	} else if (!key.compare("SupportUrl")) {
		myAJDeviceProfile.SupportUrl = value;
	} else if (!key.compare("SupportedLanguages")) {
		myAJDeviceProfile.SupportedLanguages = value;
	} else if (!key.compare("BusName")) {
		myAJDeviceProfile.BusName = value;
	} else if (!key.compare("Status")) {
		myAJDeviceProfile.Status = value;
	} else {
		cerr << "UIDUtils::setAJDeviceProfileField Invalid call" << endl;
	}
}
