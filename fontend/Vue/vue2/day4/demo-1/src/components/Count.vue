<template>
  <div>
    <h5>Count 组件</h5>
    <p>count 的值是：{{ count }}</p>
    <button @click="count++">+1</button>
  </div>
</template>

<script>
export default {
  props: {
    init: {
      default: 0,
      type: Number,
      required: true
    }
  },
  data() {
    return {
      count: this.init
    }
  },
  methods: {}
}
</script>

<style lang="less">

</style>