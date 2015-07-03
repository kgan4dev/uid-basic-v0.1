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
	AJDeviceProfile *myAJDeviceProfile;

	struct AJDeviceNotification *myAJDeviceNotification;	
	string myAJDeviceNotificationStatus;

	MYSQL *conn;

	public:
		void setAJDeviceProfileField(AJDeviceProfile *myAJDeviceProfile,string key, string value);

		void setAJDeviceNotificationField(unsigned int key_no,string value);

		void insertAJDeviceProfileToDb(AJDeviceProfile *myAJDeviceProfile);
		void updateAJDeviceBusStatusToDb(AJDeviceProfile *myAJDeviceProfile);

		UIDUtils();
		~UIDUtils();
};
#endif
