<template>
  <v-container fill-height fluid>
    <v-layout>
      <v-row align="center" justify="center">
        <v-col class="text-center" cols="12" xs="4">
          <!-- '  <v-flex class="mitten" xs12>
            <v-card max-width="344" outlined>
              <v-list-item three-line>
                <v-list-item-content>
                  <div class="overline mb-4">Fun Facts</div>
                  <v-list-item-subtitle>fjhwaef</v-list-item-subtitle>
                </v-list-item-content>
              </v-list-item>
            </v-card>
          </v-flex>' -->
          <div>
            <!-- space mellan rutorna -->
            <v-container class="grey lighten-5">
              <v-btn
                id="funfacts"
                @click="funfactsknapp"
                tile
                outlined
                color="white"
              >
                {{ funfactstext }}

                <!-- frewgew geögewrö <br/> fkanafa jgrwekgwe -->
              </v-btn>
            </v-container>
          </div>

          <div>
            <v-container class="grey lighten-5">
              <!-- <v-btn to="/settings" id="settings">Ändra färg</v-btn> -->
              <v-menu transition="scale-transition" origin="center center">
                <template v-slot:activator="{ on }">
                  <v-btn
                    id="ändrafärg"
                    @click="visa = !visa"
                    tile
                    outlined
                    color="white"
                    v-on="on"
                  >
                    Ändra färg
                  </v-btn>
                </template>
              </v-menu>
            </v-container>
          </div>

          <!-- <div>
            <v-btn to="/testing">test</v-btn>
          </div> -->
          <v-flex class="mitten" v-if="visa == true" xs11>
            <v-row justify="space-around">
              <v-col md="5" class="ml-md-auto">
                <div id="app">
                  <color-picker
                    id="colorpicker"
                    v-bind="color"
                    @input="onInput"
                  ></color-picker>
                  <pre v-html="color"></pre>
                </div>
              </v-col>

              <colorpicker />
            </v-row>
          </v-flex>
        </v-col>
      </v-row>
    </v-layout>
  </v-container>
</template>

<script>
import colorpicker from "../components/colorpicker";
// import funfacts from "../components/funfacts";

export default {
  components: {
    colorpicker,
    // funfacts,
  },

  methods: {
    funfactsknapp() {
      let random = Math.floor(Math.random() * this.facts.length);

      this.funfactstext = this.facts[random];

      this.facts= this.data.items.item;
    }
  },
  data() {
    return {
      facts: ["0", "1", "2", "3", "4", "5"],
      visa: false,
      funfacts: false,
      funfactstext: "tryck för fun facts"
    };
  }
};
</script>

<style scoped>
/* #större {
  font-size: 1.5em;
  width: 100px;
  padding: 100px !important;
} */

.mitten {
  display: flex;
  align-items: center;
  justify-content: center;
}

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

#ändrafärg {
  color: white !important;
  font-size: 1em;
  width: 300px;
  padding: 25px !important;
}

#funfacts {
  color: white !important;
  font-size: 1em;
  width: 300px;
  height: 250px;
  padding: 25px !important;
}

#colorpicker {
  padding: 25px !important;
}
</style>
