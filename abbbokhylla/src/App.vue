<template>
  <div id="app">
    <router-view />
    <!-- <color-picker v-model="color"></color-picker> -->
  </div>
</template>

<script>
// import colorpicker from '@radial-color-picker/vue-color-picker';
export default {
 
  // components: { colorpicker },
  name: "app",
  data() {
    return {
      color: {
        hue: 50,
        saturation: 100, 
        luminosity: 50, 
        alpha: 1
      },
    };
  },
};
</script>

<style>
#app {
  font-family: "Avenir", Helvetica, Arial, sans-serif;
  -webkit-font-smoothing: antialiased;
  -moz-osx-font-smoothing: grayscale;
  text-align: center;
  /* color: #2c3e50; */
  margin-top: 60px;
  background-color: #242424;
}
</style>