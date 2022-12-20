const path = require('path')

const HtmlPlugin = require('html-webpack-plugin')

const htmlPlugin = new HtmlPlugin({
    template:'./src/index.html',
    filename:'./index.html'
})

const {CleanWebpackPlugin} = require('clean-webpack-plugin')
const cleanPlugin = new CleanWebpackPlugin()

module.exports = {
    mode: 'development',

    devtool: 'nosources-source-map',

    entry: path.join(__dirname, './src/index.js'),
    output: {
        path: path.join(__dirname, 'dist'),
        filename: 'js/bundle.js'
    },

    plugins: [htmlPlugin, cleanPlugin],

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
                use: 'url-loader?limit=470&outputPath=images'
            },
            {
                test: /\.js$/,
                use: 'babel-loader',
                exclude: /node_modules/
            }
        ]
    },

    resolve: {
        alias: {
            '@': path.join(__dirname, './src')
        }
    }
}



