import $ from 'jquery'

import a from './css/index.css'
import b from './css/index.less'

import logo from './image/logo.jpg'

import './js/test/info.js'

$('.box').attr('src', logo)

$(function () {
    $('li:odd').css('background-color', 'red')
    $('li:even').css('background-color', 'pink')
})

function info(target) {
    target.info = "Person info"
}

@info
class Person {}

console.log(Person.info);
