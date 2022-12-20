const path = require('path')

const HtmlPlugin = require('html-webpack-plugin')

const htmlPlugin = new HtmlPlugin({
    template:'./src/index.html',
    filename:'./index.html'
})


module.exports = {
    mode: 'development',

    entry: path.join(__dirname, './src/index.js'),
    output: {
        path: path.join(__dirname, 'dist'),
        filename: 'bundle.js'
    },

    plugins: [htmlPlugin],

    devServer: {
        open: true,
        host: '127.0.0.1',
        port: 8080
    },

    module: {
        rules: [
            {
                test: /\.css$/, 
                use: ['style-loader', 'css-loader']
            },
            {
                test: /\.less$/,
                use: ['style-loader', 'css-loader', 'less-loader']
            },
            {
                test: /\.jpg|png|gif$/, 
                use: 'url-loader?limit=22229'
            },
            {
      