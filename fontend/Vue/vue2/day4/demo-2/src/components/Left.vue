<template>
  <div class="left-container">
    <h3>Left 组件</h3>
    <hr>
    <button @click="send">把好诗发给 Right</button>
  </div>
</template>

<script>
import bus from '@/components/eventBus'

export default {
  props: ['msg', 'user'],
  data() {
    return {
      str: '黑云压城城欲摧，渚清沙白鸟飞回，借问酒家何处是，半江瑟瑟半江红'
    }
  },
  methods: {
    send() {
      bus.$emit('share', this.str)
    }
  }
}
</script>

<style lang="less">
.left-container {
  padding: 0 20px 20px;
  background-color: orange;
  min-height: 250px;
  flex: 1;
}
</style>
