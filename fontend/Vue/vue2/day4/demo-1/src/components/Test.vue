<template>
  <div class="test-container">
    <h3 id="myh3">Test.vue 组件 --- {{ books.length }} 本图书</h3>
  </div>
</template>

<script>
export default {
  props: ['info'],
  data() {
    return {
      message: 'hello vue.js',
      books: []
    }
  },
  methods: {
    show() {
      console.log('调用了 Test 组件的 show 方法')
    },
    initBookList() {
      const xhr = new XMLHttpRequest()
      xhr.addEventListener('load', () => {
        const res = JSON.parse(xhr.responseText)
        this.books = res.data
        console.log(res)
      })
      xhr.open('GET', 'http://www.liulongbin.top:3006/api/getbooks')
      xhr.send()
    }
  },
  beforeCreate() {
    // console.log(this.info)
    // console.log(this.message)
    // this.show()
  },
  created() {
    console.log(this.info)
    console.log(this.message)
    this.show()
    this.initBookList()
  }
}
</script>

<style lang="less" scoped>
.test-container {
  background-color: pink;
  height: 200px;
}
</style>