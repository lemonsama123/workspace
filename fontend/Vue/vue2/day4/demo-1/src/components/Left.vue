<template>
  <div class="left-container">
    <h3>Left 组件</h3>
    <Count :init="9"></Count>
  </div>
</template>

<script>
export default {}
</script>

<style lang="less" scoped>

.left-container {
  padding: 0 20px 20px;
  background-color: orange;
  min-height: 250px;
  flex: 1;
}

h3 {
  color: red
}

/deep/ h5 {
  color: pink;
}
</style>
