## ˵��

### 1 Ӳ����Ϣ

ESP8266+DHT11

��Ʒ�������δ����http://www.nafuture.cn/newnet/al.html

 [������̳������������](https://shop154838422.taobao.com/?spm=a1z10.1-c.0.0.13275d23ylAfRX)�����Ա����ӣ�https://item.taobao.com/item.htm?id=625111319838&price=4.9&sourceType=item&sourceType=item&suid=d1d2ac3b-1c78-4bcd-97e0-6bbc1cff1936&shareUniqueId=3390089642&ut_sk=1.XqpPAaymHSkDALudhOi1gv3z_21646297_1600003348163.TaoPassword-QQ.1&un=171e89c074dd66d50d92f5aa52e6dceb&share_crt_v=1&spm=a2159r.13376460.0.0&sp_tk=RUJKVmNWS1pBMHo=&cpp=1&shareurl=true&short_name=h.VxzZS0q&bxsign=scd16000038058075be83c1fc24c4382b84c9f37bff07a7f&app=chrome

> usb�ӿ��Ѿ�����io0��ӦUSB��ID��tx��rx��Ӧusb��d+d-��gpio12Ϊled��gpio4��dht����������ժ�����ۣ�

�����������Ŀǰ���Ե�APP���޷�������ѯ��ʪ�ȣ��в�֪ԭ�򣩣��ʽ��ж��ο�����

�ɸ�������ʹ��otgת���߽��г�����¼����������

![img](https://img.alicdn.com/imgextra/i2/1799820918/O1CN01LqjcHm1IeUCckxVZ9_!!1799820918.jpg)

### 2 ��������

**ƽ̨��**

Arduinoƽ̨��VSCode+arduino��

**����⣺**

blinker��ƿƼ���https://www.diandeng.tech/home

Adafruit_Sensor DHT��

### 3 ����˵���뿪���ƻ�

Ŀǰ��ʵ����ʹ�� ***��ƿƼ�*** ƽ̨��ȡ��ʪ����Ϣ������ļ򵥹��ܣ�2��ɼ�һ�Σ�����LEDδ�������Ľϴ���������Ϣֱ��д�ڳ����С���

Ŀǰʹ�õ�ƿƼ�Demo�����������Լ��mqtt���������ڿӣ�

- [x] ��ȡ��ʪ����Ϣ

- [x] ��ȡ����

- [ ] �͹���ģʽ

- [ ] һ������

  ��Ե���¡�

ĿǰԴ������ڵ�ƿƼ�Demo΢�Ķ�����������չ����̡̳�

### 4 ʹ��˵��

1.�ڵ�ƿƼ�����ע���˺Ų�����APP�����ս̳�����豸��

2.�������޸� `Your Device Secret Key`��`Your WiFi network SSID or name`��`Your WiFi network WPA password or WEP key`��

3.���������¼��

4.������ʾ��¶ȡ�ʪ�ȡ���������

![](img/����.jpg)

5.���ô�����������С��ͬѧ�ã���

```js
[
	{
		"source":"switch",
		"source_zh":"����״̬",
		"state":["on","off"],
		"state_zh":["����","�ر�"]
	},
	{
		"source":"temp",
		"source_zh":"�¶�",
		"range":[-20,50],
		"unit":"��"
	},
	{
		"source":"humi",
		"source_zh":"ʪ��",
		"range":[0,100],
		"unit":"%"
	},
	{
		"source":"BatteryVolt",
		"source_zh":"��ѹ",
		"range":[0,5000],
		"unit":"mV"
	}
]
```



��ϸ�̳̲μ�������https://www.diandeng.tech/doc/temperature-and-humidity-sensor

### 5 ��Ȩ

Ӳ����ƹ���δ�����С�

���ƽ̨���ƿƼ����С�

���ֽ����봴����������Ʒ���ۣ�����ȫԭ����

��ֹ���ã���Demo�����ο���