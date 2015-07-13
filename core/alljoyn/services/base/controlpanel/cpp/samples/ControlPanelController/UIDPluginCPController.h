#ifndef UIDPLUGINCPCONTROLLER_H
#define UIDPLUGINCPCONTROLLER_H

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

struct AJDeviceCPActionWidget {
	string name;
	string version;
	string secured;
	string enabled;
	string label;
	string bgColor;
	string hints;
	string ChildDialog;
	string ChildName;
};

struct AJDeviceCPDialogWidget {
	string name;
	string version;
	string secured;
	string enabled;
	string label;
	string bgColor;
	string hints;
	string message;
	string numActions;
	string LabelforAction1;
	string LabelforAction2;
	string LabelforAction3;
};

class UIDUtils {
	AJDeviceProfile myAJDeviceProfile;
	AJDeviceNotification myAJDeviceNotification;

	AJDeviceCPActionWidget myAJDeviceCPActionWidget;
	AJDeviceCPDialogWidget myAJDeviceCPDialogWidget;

	MYSQL *conn;

	public:
		UIDUtils();
		~UIDUtils();

		void setAJDeviceProfileField(string key, string value);
		string getAJDeviceProfileField(string key);

		void insertAJDeviceProfileToDb();
		void updateAJDeviceBusStatusToDb();
		void DeviceToCheckStatus();

		void setAJDeviceNotificationField(string key, string value);
		string getAJDeviceNotificationField(string key);

		void insertAJDeviceNotificationToDb();

		void setAJDeviceCPActionWidgetField(string key, string value);
		string getAJDeviceCPActionWidgetField(string key);

		void insertAJDeviceCPActionWidgetToDb();

		void setAJDeviceCPDialogWidgetField(string key, string value);
		string getAJDeviceCPDialogWidgetField(string key);

		void insertAJDeviceCPDialogWidgetToDb();

};
#endif
