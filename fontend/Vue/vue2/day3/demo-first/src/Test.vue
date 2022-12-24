<template>
    <div>
        <div class="test-box">
            <h3>这是用户自定义的 Test.vue --- {{ username }}</h3>
            <button @click="changName">修改用户名</button>
        </div>
        <div>123</div>
    </div>
</template>

<script>
export default {
    data() {
        return {
            username: 'zs'
        }
    },
    methods: {
        changName() {
            this.username = '哇哈哈'
        }
    }
}
</script>

<style lang="less">
.test-box {
    background-color: pink;
    h3 {
        color: red;
    }
}
</style>