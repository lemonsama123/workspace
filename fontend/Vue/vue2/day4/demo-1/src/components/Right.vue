<template>
  <div class="right-container">
    <h3>Right 组件</h3>
    <Count :init="6"></Count>
  </div>
</template>

<script>
export default {}
</script>

<style lang="less">
.right-container {
  padding: 0 20px 20px;
  background-color: lightskyblue;
  min-height: 250px;
  flex: 1;
}

h5 {
  color: pink;
}
</style>
