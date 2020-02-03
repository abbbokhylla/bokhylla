<template>
  <div>
    <color-picker v-bind="color" @input="onInput"></color-picker>
    <!-- <h1 v-text="msg"></h1> -->
    <!-- <pre v-html="color"></pre> -->
  </div>

  <!-- <div>
    <color-picker v-model="color" @input="onInput"></color-picker>
    <color-picker v-bind="color" @input="onInput"></color-picker>
    <h1 v-text="msg"></h1>

    <pre v-html="color"></pre>
  </div> -->
</template>

<script>
import ColorPicker from "@radial-color-picker/vue-color-picker";
var mqtt = require("mqtt"),
  /* eslint-disable */
  url = require("url");

export default {
  created() {
    // this.fetch();
    this.connect();
  },
  components: { ColorPicker },
  data() {
    return {
      connected: false,
      client: "hemsidan",
      user: "william.johansson@abbindustrigymnasium.se",
      pass: "creativetalk",
      message: "tjena",
      R: "1",
      G: "3",
      B: "66",
      msg: "",
      color: {
        hue: 50,
        saturation: 100,
        luminosity: 50,
        alpha: 1
      }
    };
  },
  methods: {
    onInput: function(hue) {
      this.color.hue = hue;
      this.send();
      //   this.msg=hue;
      //   console.log(hue)
    },

    HSLToRGB(h, s, l) {
      // Must be fractions of 1
      s /= 100;
      l /= 100;

      let c = (1 - Math.abs(2 * l - 1)) * s,
        x = c * (1 - Math.abs(((h / 60) % 2) - 1)),
        m = l - c / 2,
        r = 0,
        g = 0,
        b = 0;

      if (0 <= h && h < 60) {
        r = c;
        g = x;
        b = 0;
      } else if (60 <= h && h < 120) {
        r = x;
        g = c;
        b = 0;
      } else if (120 <= h && h < 180) {
        r = 0;
        g = c;
        b = x;
      } else if (180 <= h && h < 240) {
        r = 0;
        g = x;
        b = c;
      } else if (240 <= h && h < 300) {
        r = x;
        g = 0;
        b = c;
      } else if (300 <= h && h < 360) {
        r = c;
        g = 0;
        b = x;
      }
      r = Math.round((r + m) * 255);
      g = Math.round((g + m) * 255);
      b = Math.round((b + m) * 255);
      return [r, g, b];
      //   return "(" + r + "," + g + "," + b + ")";
    },
    connect() {
      var mqtt_url = "maqiatto.com";
      var url = "mqtt://" + mqtt_url;
      var options = {
        port: 8883,
        clientId:
          "mqttjs_" +
          Math.random()
            .toString(16)
            .substr(2, 8),
        username: this.user,
        password: this.pass
      };
      // user = this.options.username
      // pass = this.options.password
      /* eslint-disable */
      console.log("connecting");
      this.client = mqtt.connect(url, options);
      /* eslint-disable */
      console.log("connected?");
      this.client
        .on("error", function(error) {
          /* eslint-disable */
          console.log("no");
          this.connected = false;
          /* eslint-disable */
          console.log(this.Alert, this.connected);
        })
        .on("close", function(error) {
          /* eslint-disable */
          console.log("no");
          this.connected = false;
        });
      this.connected = true;
    },
    send() {
      let rgb = this.HSLToRGB(
        this.color.hue,
        this.color.saturation,
        this.color.luminosity
      );
      /* eslint-disable */
      console.log("rgb: " + rgb);
      this.R = rgb[0];
      this.G = rgb[1];
      this.B = rgb[2];
      this.client.publish(
        "william.johansson@abbindustrigymnasium.se/r1",
        this.R
      );
      this.client.publish(
        "william.johansson@abbindustrigymnasium.se/g1",
        this.G
      );
      this.client.publish(
        "william.johansson@abbindustrigymnasium.se/b1",
        this.B
      );
    }
  }
};
</script>

<style>
@import "~@radial-color-picker/vue-color-picker/dist/vue-color-picker.min.css";
#app {
  font-family: "Avenir", Helvetica, Arial, sans-serif;
  -webkit-font-smoothing: antialiased;
  -moz-osx-font-smoothing: grayscale;
  display: flex;
  flex-direction: column;
  align-items: center;
  color: #2c3e50;
  margin-top: 40px;
}

/* h1 {
  font-weight: normal;
} */

/* pre {
  min-width: 275px;
  padding: 15px 30px;
  background: #f8f8f8;
  color: #525252;
  font-size: 15px;
  font-weight: bold;
  line-height: 1.6;
  margin: 0;
} */

@media (max-width: 420px) {
  /* h1 {
    font-size: 1.4em;
  } */
}
</style>
