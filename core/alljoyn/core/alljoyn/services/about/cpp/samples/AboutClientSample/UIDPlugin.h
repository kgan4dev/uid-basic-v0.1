#ifndef UIDPLUGIN_H
#define UIDPLUGIN_H

#include <iostream>
#include <mysql/mysql.h>

using namespace std;

struct AJDeviceProfile {
	string AJSoftwareVersion;
	string AppId;
	string AppName;
	string DateOfManufacture;
	string DefaultLanguage;
	string Description;
	string DeviceId;
	string DeviceName;
	string HardwareVersion;
	string Manufacturer;
	string ModelNumber;
	string SoftwareVersion;
	string SupportUrl;
	string SupportedLanguages;
	string BusName;
	string Status;
};

struct AJDeviceNotification {
	string MessageId;
	string DeviceId;
	string DeviceName;
	string AppId;
	string AppName;
	string SenderBusName;
	string MessageType;
	string Version;
	string Language;
	string Message;
};

class UIDUtils {
	AJDeviceProfile myAJDeviceProfile;
	MYSQL *conn;

	public:
		void setAJDeviceProfileField(string key, string value);
		string getAJDeviceProfileField(string key);

		void insertAJDeviceProfileToDb();
		void updateAJDeviceBusStatusToDb();

		UIDUtils();
		~UIDUtils();
};
#endif
