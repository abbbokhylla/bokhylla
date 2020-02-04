# app

## Project setup
```
npm install
```
### If something isn´t up to date
```
npm audit fix
```

### Compiles and hot-reloads for development
```
npm run serve
```

### Compiles and minifies for production
```
npm run build
```

### Lints and fixes files
```
npm run lint
```

### Customize configuration
See [Configuration Reference](https://cli.vuejs.org/config/).


### For Arduino:
Make sure you have installed the Arduino Library 
```
EspMQTTClient
```
Change the Client Credentials to your own information (Make sure to pick a good client name!)
```
EspMQTTClient client(
 "ABB_Indgym_Guest",           // Wifi ssid                       CHANGE THIS
  "Welcome2abb",           // Wifi password                       CHANGE THIS
  "maqiatto.com",  // MQTT broker ip                              
  1883,             // MQTT broker port
  "william.johansson@abbindustrigymnasium.se", // MQTT username   CHANGE THIS
  "creativetalk",       // MQTT password                          CHANGE THIS
  "william1",          // Client name                             CHANGE THIS
  onConnectionEstablished, // Connection established callback
  true,             // Enable web updater
  true              // Enable debug messages
);
```
