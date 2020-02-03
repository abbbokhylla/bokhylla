import Vue from 'vue'             //importerar vue och andra komponenter som används i applikationen
import Router from 'vue-router' //vvv ignorerar fel
// eslint-disable-next-line 
import Start from './views/start.vue'
// eslint-disable-next-line 
// import Game from './views/game.vue'
// eslint-disable-next-line 
import Settings from './views/settings.vue'
// eslint-disable-next-line 
import Testing from './views/testing.vue'

Vue.use(Router)

export default new Router({
  mode: 'history',
  base: process.env.BASE_URL,
  routes: [
    {
      path: '/',                                             
      name: 'Startsida',                                        
      component: () => import('./views/start.vue')     
    },
    // {
    //     path: '/game',                                             
    //     name: 'Spelsida',                                        
    //     component: () => import('./views/game.vue')     
    // },
    {
      path: '/settings',
      name: 'Settings',
      component: () => import('./views/settings.vue')
    },
    {
      path: '/testing',
      name: 'Testing',
      component: () => import('./views/testing.vue')
    }
  ]
})