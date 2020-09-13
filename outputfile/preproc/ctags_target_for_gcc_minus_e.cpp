# 1 "f:\\Projects\\arduino\\DHT11withBlink\\DHT.ino"
# 1 "f:\\Projects\\arduino\\DHT11withBlink\\DHT.ino"
/* *****************************************************************

 *

 * Download latest Blinker library here:

 * https://github.com/blinker-iot/blinker-library/archive/master.zip

 * 

 * 

 * Blinker is a cross-hardware, cross-platform solution for the IoT. 

 * It provides APP, device and server support, 

 * and uses public cloud services for data transmission and storage.

 * It can be used in smart home, data monitoring and other fields 

 * to help users build Internet of Things projects better and faster.

 * 

 * Make sure installed 2.7.2 or later ESP8266/Arduino package,

 * if use ESP8266 with Blinker.

 * https://github.com/esp8266/Arduino/releases

 * 

 * Make sure installed 1.0.4 or later ESP32/Arduino package,

 * if use ESP32 with Blinker.

 * https://github.com/espressif/arduino-esp32/releases

 * 

 * Docs: https://diandeng.tech/doc

 *       https://github.com/blinker-iot/blinker-doc/wiki

 * 

 * *****************************************************************

 * 

 * Blinker �����ص�ַ:

 * https://github.com/blinker-iot/blinker-library/archive/master.zip

 * 

 * Blinker ��һ�׿�Ӳ������ƽ̨������������������ṩAPP�ˡ��豸�ˡ�

 * ��������֧�֣�ʹ�ù����Ʒ���������ݴ���洢�����������ܼҾӡ�

 * ���ݼ������򣬿��԰����û����ø���ش��������Ŀ��

 * 

 * ���ʹ�� ESP8266 ���� Blinker,

 * ��ȷ����װ�� 2.7.2 ����µ� ESP8266/Arduino ֧�ְ���

 * https://github.com/esp8266/Arduino/releases

 * 

 * ���ʹ�� ESP32 ���� Blinker,

 * ��ȷ����װ�� 1.0.4 ����µ� ESP32/Arduino ֧�ְ���

 * https://github.com/espressif/arduino-esp32/releases

 * 

 * �ĵ�: https://diandeng.tech/doc

 *       https://github.com/blinker-iot/blinker-doc/wiki

 * 

 * *****************************************************************/
# 49 "f:\\Projects\\arduino\\DHT11withBlink\\DHT.ino"
# 50 "f:\\Projects\\arduino\\DHT11withBlink\\DHT.ino" 2

char auth[] = "ad2d9badc048";//"Your Device Secret Key";
char ssid[] = "sunny";//"Your WiFi network SSID or name";
char pswd[] = "12345678";//"Your WiFi network WPA password or WEP key";

BlinkerNumber HUMI("humi");
BlinkerNumber TEMP("temp");
BlinkerNumber ADC("BatteryVolt");//kong��blinker�ֻ�APP�����ݼ��������Լ�ѡ����

int V;
int Val;

// Download Adafruit DHT-sensor-library library here:
// https://github.com/adafruit/DHT-sensor-library
# 65 "f:\\Projects\\arduino\\DHT11withBlink\\DHT.ino" 2




//#define DHTTYPE DHT22   // DHT 22  (AM2302), AM2321
//#define DHTTYPE DHT21   // DHT 21 (AM2301)

DHT dht(D4, 11 /**< DHT TYPE 11 */ /* DHT 11*/);

uint32_t read_time = 0;

float humi_read, temp_read, volt_read;


void dataRead(const String & data)
{
    BLINKER_LOG("Blinker readString: ", data);

    Blinker.vibrate();

    uint32_t BlinkerTime = millis();

    Blinker.print("millis", BlinkerTime);
}

void heartbeat()
{
    HUMI.print(humi_read);
    TEMP.print(temp_read);
    ADC.print(volt_read);
}

void setup()
{
    Serial.begin(115200);
    BLINKER_DEBUG.stream(Serial);

    pinMode(2, 0x01);
    digitalWrite(2, 0x0);

    Blinker.begin(auth, ssid, pswd);
    Blinker.attachData(dataRead);
    Blinker.attachHeartbeat(heartbeat);

    dht.begin();
}

void loop()
{
    Blinker.run();

    if (read_time == 0 || (millis() - read_time) >= 2000)
    {
        read_time = millis();

        float h = dht.readHumidity();
        float t = dht.readTemperature();

        if (isnan(h) || isnan(t)) {
            BLINKER_LOG("Failed to read from DHT sensor!");
            return;
        }

        V = analogRead(A0);//��ȡADC
        Val = V * 5000 / 1023 ;//����ΪmV

        float hic = dht.computeHeatIndex(t, h, false);

        humi_read = h;
        temp_read = t;
        volt_read = Val;

        BLINKER_LOG("Humidity: ", h, " %");
        BLINKER_LOG("Temperature: ", t, " *C");
        BLINKER_LOG("Heat index: ", hic, " *C");
        BLINKER_LOG("Battery Volt: ", volt_read, " mV");
    }
}
