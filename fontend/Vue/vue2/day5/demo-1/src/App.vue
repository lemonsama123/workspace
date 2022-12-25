<template>
  <div class="app-container">
    <h1 ref="myh1">App 根组件</h1>
    <button @click="showThis">打印 this</button>
    <hr/>

    <div class="box">
      <!-- 渲染 Left 组件和 Right 组件 -->
    </div>
  </div>
</template>

<script>
export default {
  methods: {
    showThis() {
      console.log(this)
      this.$refs.myh1.style.color = 'red'
    }
  }
}
</script>

<style lang="less">
.app-container {
  padding: 1px 20px 20px;
  background-color: #efefef;
}

.box {
  display: flex;
}
</style>
