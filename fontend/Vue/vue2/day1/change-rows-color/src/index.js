import $ from 'jquery'

import a from './css/index.css'
import b from './css/index.less'

import logo from './image/logo.jpg'

$('.box').attr('src', logo)

$(function () {
    $('li:odd').css('background-color', 'red')
    $('li:even').css('background-color', 'pink')
})
