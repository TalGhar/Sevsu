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

Route::get('/awards-receive', 'App\Http\Controllers\AwardsController@receive');
Route::post('/awards-store', 'App\Http\Controllers\AwardsController@store');
Route::post('/awards-edit', 'App\Http\Controllers\AwardsController@edit');
Route::post('/awards-delete', 'App\Http\Controllers\AwardsController@delete');

Route::get('/news-receive', 'App\Http\Controllers\NewsController@receive');
Route::post('/news-store', 'App\Http\Controllers\NewsController@store');
Route::post('/news-edit', 'App\Http\Controllers\NewsController@edit');
Route::post('/news-delete', 'App\Http\Controllers\NewsController@delete');
Route::get('/news-latest', 'App\Http\Controllers\NewsController@latest');

Route::get('/history-receive', 'App\Http\Controllers\HistoryController@receive');
Route::post('/history-store', 'App\Http\Controllers\HistoryController@store');
Route::post('/history-edit', 'App\Http\Controllers\HistoryController@edit');
Route::post('/history-delete', 'App\Http\Controllers\HistoryController@delete');

Route::get('/boats-receive', 'App\Http\Controllers\BoatsController@receive');
Route::post('/boats-sell', 'App\Http\Controllers\BoatsController@sell');
Route::post('/boats-rent', 'App\Http\Controllers\BoatsController@rent');










