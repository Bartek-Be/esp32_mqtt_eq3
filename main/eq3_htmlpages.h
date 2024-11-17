
const char pageheader[] = R"EOF(
<!DOCTYPE html>
<html>
<head>
    <meta charset="utf-8"><meta name="viewport" content="width=device-width,initial-scale=1,user-scalable=no"/>
    <title>EQ3 status</title>
</head>

<body>
<div style="text-align:center;">
)EOF";
//<div style="zoom: 350%%;">";

const char pagefooter_a[] = R"EOF(
<table style="margin:1em auto;">
<tbody>
    <tr><td><a href="/command">Control EQ3 device</a></td><td> | </td><td><a href="/status" style="color: #C89600;">Status</a></td></tr>
    <tr><td><a href="/viewlog">View EQ3 status log</a></td><td> | </td><td><a href="/config" style="color: #C89600;">Configuration</a></td></tr>
    <tr><td><a href="/getdevices">List of EQ3 devices seen</a></td><td> | </td><td><a href="/upload" style="color: #C89600;">Update software</a></td></tr>
    <tr><td><a href="/scan">Rescan for EQ3 devices</a></td><td> | </td><td><a href="/restartnow" style="color: #FF0000;">Reboot ESP</a></td></tr>
</tbody>
</table>
<div style="font-size:12px;"><hr/>
    <a href="https://github.com/softypit/esp32_mqtt_eq3" target="_blank" style="color: #AAA;">EQ3-MQTT-ESP32)EOF";

const char pagefooter_b[] = " "EQ3_MAJVER"."EQ3_MINVER""EQ3_EXTRAVER" ";

const char pagefooter_c[] = R"EOF(by SoftyPIT</a><br/>
    <a href="https://github.com/Bartek-Be/esp32_mqtt_eq3" target="_blank" style="color: #AAA;">fork</a></div>
</div>

</body>
</html>
)EOF";

const char pageemptyfooter[] = R"EOF(
</div>

</body>
</html>
)EOF";

const char selectap[] = R"EOF(
<h1>Select WiFi</h1>
<form action="configSubmit" method="post">
<table style="margin:1em auto;">
<tbody>
    <tr><td>SSID:</td><td><input type="text" autocorrect="off" autocapitalize="none" name="ssid" value="%s" /></td></tr>
    <tr><td>Password:</td><td><input type="password" autocorrect="off" autocapitalize="none" name="password" value="%s" placeholder="hidden" /></td></tr>
    <tr><td>MQTT URL:</td><td><input type="text" autocorrect="off" autocapitalize="none" name="mqtturl" value="%s" /></td></tr>
    <tr><td>MQTT username:</td><td><input type="text" autocorrect="off" autocapitalize="none" name="mqttuser" value="%s" /></td></tr>
    <tr><td>MQTT password:</td><td><input type="password" autocorrect="off" autocapitalize="none" name="mqttpass" value="%s" placeholder="hidden" /></td></tr>
    <tr><td>MQTT ID:</td><td><input type="text" autocorrect="off" autocapitalize="none" name="mqttid" value="%s" /></td></tr>
    <tr><td>NTP enabled:</td><td><input type="checkbox" name="ntpenabled" value="true" %s/></td></tr>
    <tr><td>NTP server 1:</td><td><input type="text" autocorrect="off" autocapitalize="none" name="ntpserver1" value="%s" /></td></tr>
    <tr><td>NTP server 2:</td><td><input type="text" autocorrect="off" autocapitalize="none" name="ntpserver2" value="%s" /></td></tr>
    <tr><td>Timezone:</td><td><input type="text" autocorrect="off" autocapitalize="none" name="ntptimezone" value="%s" /></td></tr>
    <tr><td>IP address:</td><td><input type="text" autocorrect="off" autocapitalize="none" name="ip" value="%s" /></td></tr>
    <tr><td>Gateway address:</td><td><input type="text" autocorrect="off" autocapitalize="none" name="gw" value="%s" /></td></tr>
    <tr><td>Netmask:</td><td><input type="text" autocorrect="off" autocapitalize="none" name="netmask" value="%s" /></td></tr>
    <tr><td>DNS server 1:</td><td><input type="text" autocorrect="off" autocapitalize="none" name="dns1ip" value="%s" /></td></tr>
    <tr><td>DNS server 2:</td><td><input type="text" autocorrect="off" autocapitalize="none" name="dns2ip" value="%s" /></td></tr>
</tbody>
</table>
<div><input type="submit" value="Submit"></div>
</form>
<div>
    The IP address, gateway address and netmask are optional. If not supplied
    these values will be issued by the WiFi access point.
</div>
)EOF";

const char devlisthead[] = R"EOF(
<title>EQ3 devices</title>
<div><h1>EQ3 devices found</h1></div>
<table style="margin:1em auto;">
<tbody> 
    )EOF";

const char devlistentry[] = "<tr><td>Device:</td><td>%02X:%02X:%02X:%02X:%02X:%02X</td><td>rssi</td><td>%d</td></tr>";

const char devlistfoot[] = R"EOF(
</tbody>
</table>
)EOF";

const char nodevices[] = R"EOF(
<title>No devices found</title>
<div><h1>No devices found</h1></div>
)EOF";

const char loglisthead[] = R"EOF(<title>EQ3 device log</title>
<div><h1>EQ3 device log</h1></div>
<table style="margin:1em auto;">
<tbody> 
    )EOF";

//const char loglistentry[] = "<tr><td>%s</td></tr>";

const char loglistfoot[] = R"EOF(
</tbody>
</table>
)EOF";

const char connectedstatus[] = R"EOF(
<title>EQ3 status</title> 
<div><h1>EQ3 relay status</h1></div>
<table style="margin:1em auto;">
<tbody>
    <tr><td>MQTT URL:</td><td>%s</td></tr>
    <tr><td>MQTT ID:</td><td>%s</td></tr>
    <tr><td>MQTT status:</td><td>%s</td></tr>
    <tr><td>Uptime:</td><td>%d days %02d:%02d:%02d</td></tr>
</tbody>
</table>
)EOF";

const char apstatus[] = R"EOF(
<title>Please configure me</title> 
<div><h1>Please configure me</h1></div>
)EOF";

const char upload[] = R"EOF(
<title>upload firmware</title> 
<div><h1>Upload new software</h1></div>
<form action="otaupload" method="POST" enctype="multipart/form-data">
<table style="margin:1em auto;">
<tbody>
    <tr><td><input type="file" name="fileupload" value="fileupload" id="fileupload"></td></tr>
    <tr><td><input type="submit" value="Upload and apply"></td></tr>
</tbody>
</table>
</form>
)EOF";

const char uploadsuccess[] = R"EOF(
<title>uploaded firmware</title> 
<div>
    <h1>Upload status</h1>
    Firmware upload success
    %lu bytes transferred
    <br/><a href="/restartnow">Reboot ESP</a> to apply new image
</div>
)EOF";

const char uploadfailed[] = R"EOF(
<title>uploaded firmware</title> 
<div>
    <h1>Upload status</h1>
    Firmware upload failed
</div>
)EOF";

const char uploadcomplete[] = R"EOF(
<meta http-equiv="refresh" content="1;URL="/otastatus"">
<title>upload complete</title>
<div><h1>Upload complete</h1></div>
)EOF";

const char scanning[] = R"EOF(
<meta http-equiv="refresh" content="5;URL="/getdevices"">
<div><h1>Scanning...</h1></div>
)EOF";

const char rebooting[] = R"EOF(
<meta http-equiv="refresh" content="40;URL="/"">
<div><h1>Rebooting...</h1></div>
)EOF";

const char command_device_head[] = R"EOF(
<title>EQ3 device log</title> 
<div><h1>control EQ-3</h1></div>
<form action="sendCommand" method="post"> 
<table style="margin:1em auto;">
<tbody>
    <tr><td><select name="device">
        )EOF";

const char select_device_entry[] = "<option value=\"%s\">%s</option>";

const char command_post_device[] = R"EOF(
    </select></td>
    <td><select name="command">
        <option value="unlock">unlock</option>
        <option value="lock">lock</option>
        <option value="boost">boost</option>
        <option value="unboost">unboost</option>
        <option value="auto">auto</option>
        <option value="manual">manual</option>
        <option value="settemp">settemp</option>
        <option value="off">closed (off)</option>
        <option value="on">open (on)</option>
        <option value="offset">offsettemp</option>
        <option value="settime">settime</option>
    </select></td>
    <td><input type="text" name="value"></td></tr>
    <tr><td><input type="submit" value="Submit"></td></tr>
</tbody>
</table>
</form>
)EOF";

const char commandsubmitted[] = R"EOF(
<title>Command submitted</title> 
<div><h1>Command submitted</h1></div>
)EOF";

const char commanderror[] = R"EOF(
<title>Invalid command</title> 
<div><h1>Invalid command</h1></div>
)EOF";
