#ifndef UIDPLUGINNOTIFICATION_H
#define UIDPLUGINNOTIFICATION_H

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
	string Status;
};

class UIDUtils {
	AJDeviceProfile myAJDeviceProfile;
	AJDeviceNotification myAJDeviceNotification;

	MYSQL *conn;

	public:
		void setAJDeviceProfileField(string key, string value);
		string getAJDeviceProfileField(string key);

		void setAJDeviceNotificationField(string key, string value);
		string getAJDeviceNotificationField(string key);

		void insertAJDeviceProfileToDb();
		void updateAJDeviceBusStatusToDb();
		void DeviceToCheckStatus();

		void insertAJDeviceNotificationToDb();

		UIDUtils();
		~UIDUtils();
};
#endif
