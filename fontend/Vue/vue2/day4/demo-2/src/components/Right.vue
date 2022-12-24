<template>
  <div class="right-container">
    <h3>Right 组件 --- {{ count }}</h3>
    <button @click="add">+1</button>
    <hr>
    <p>{{msgFromLeft}}</p>
  </div>
</template>

<script>
import bus from '@/components/eventBus'

export default {
  data() {
    return {
      count: 0,
      msgFromLeft: ''
    }
  },
  methods: {
    add() {
      this.count++
      this.$emit('numchange', this.count)
    }
  },
  created() {
    bus.$on('share', str => {
      this.msgFromLeft = str
    })
  }
}
</script>

<style lang="less">
.right-container {
  padding: 0 20px 20px;
  background-color: lightskyblue;
  min-height: 250px;
  flex: 1;
}
</style>
