<template>
  <v-row justify="space-around">
    <v-col cols="1" md="2">
      <div id="app">
        <color-picker v-bind="color" @input="onInput"></color-picker>
        <pre v-html="color"></pre>
      </div>
    </v-col>
    <colorpicker />
  </v-row>
</template>

<script>
import colorpicker from "../components/colorpicker";

export default {
  components: {
    colorpicker
  }
};
</script>

<style scoped>
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

h1 {
  font-weight: normal;
}

pre {
  min-width: 275px;
  padding: 15px 30px;
  background: #f8f8f8;
  color: #525252;
  font-size: 15px;
  font-weight: bold;
  line-height: 1.6;
  margin: 0;
}

@media (max-width: 420px) {
  h1 {
    font-size: 1.4em;
  }
}
</style>
