<?php

namespace App\Http\Controllers;

use Illuminate\Http\Request;
use Illuminate\Support\Facades\Log;

class AuthController extends Controller
{
    public function test(Request $request)
    {
        $mail = $request->input('email');
        return $mail;
    }
}
