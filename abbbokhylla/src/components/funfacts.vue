<template>
<div @click="funfactsknapp"> 
    <p  tile outlined > 
        
  <span> {{ funfactstext }} </span> </p>
</div>
</template>

<script>
const axios = require('axios').default;
export default {
methods:{
    async fetch(){
        const{data}=await axios.get("https://shy0h1cogf.execute-api.us-east-1.amazonaws.com/Beta/funfact");
        /*eslint-disable*/
        console.log(data.body.Items)
        this.facts=data.body.Items;

  },
    funfactsknapp() {
      let random = Math.floor(Math.random() * this.facts.length);

      this.funfactstext = this.facts[random].Fact;
      //this.funfactstext = this.facts.items.item[random];
      // this.funfactstext = this.facts[random];

      //this.facts= this.facts.items.item;
    //   this.facts= this.data.items.item;
      //this.facts= this.data;
    }
 },
 data(){
     return{
         facts:[],
         funfactstext: "TRYCK FÖR FUN FACTS"

     }
 },
 created(){
this.fetch();
 }
}
</script>

<style scoped>


div {
        display: inline-block; 
    text-decoration: none;
  font-size: 20px;  
  width: 300px;
  height: 250px;

  border: white 0.5px solid;
  line-height: 250px;
  text-align: center;
}
span {
    color:white;
  display: inline-block;
  vertical-align: middle;
  line-height: normal;
}

</style>