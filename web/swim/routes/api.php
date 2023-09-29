<?php

use Illuminate\Http\Request;
use Illuminate\Support\Facades\Route;
use App\Http\Controllers\AuthController;
use App\Http\Controllers\PlaceController;

/*
|--------------------------------------------------------------------------
| API Routes
|--------------------------------------------------------------------------
|
| Here is where you can register API routes for your application. These
| routes are loaded by the RouteServiceProvider and all of them will
| be assigned to the "api" middleware group. Make something great!
|
*/

Route::middleware('auth:sanctum')->get('/user', function (Request $request) {
    return $request->user();
});

Route::post('/register', 'App\Http\Controllers\AuthController@register');
Route::post('/login', 'App\Http\Controllers\AuthController@login');
Route::post('/place', 'App\Http\Controllers\PlaceController@store');
Route::post('/store', 'App\Http\Controllers\AwardsController@store');
Route::get('/receive', 'App\Http\Controllers\AwardsController@receive');
Route::post('/awards-edit', 'App\Http\Controllers\AwardsController@edit');
Route::post('/awards-delete', 'App\Http\Controllers\AwardsController@delete');




