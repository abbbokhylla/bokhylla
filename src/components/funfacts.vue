<template>
   <v-btn @click="fetch"> </v-btn>

</template>

<script>
const axios = require('axios').default;
export default {
methods:{
    async fetch(){
        const{data}=await axios.get("https://shy0h1cogf.execute-api.us-east-1.amazonaws.com/Beta/funfact");
        /*eslint-disable*/
        console.log(data)
  }
 }
}
</script>

<style>

</style>
