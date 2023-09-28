<?php

namespace App\Http\Controllers;

use App\Models\Client;
use Illuminate\Http\Request;
use Illuminate\Support\Facades\Hash;

class AuthController extends Controller
{

    public function register(Request $request)
    {
        $request->validate([
            'name' => 'required',
            'surname' => 'required',
            'patron' => 'required',
            'email' => 'required|email|unique:clients',
            'password' => 'required|min:6',
        ]);

        Client::create([
            'name' => $request->name,
            'surname' => $request->surname,
            'patron' => $request->patron,
            'email' => $request->email,
            'password' => $request->password
        ]);
    }

    public function login(Request $request)
    {
        $client = Client::where('email', $request->email)->first();
        if ($client && $request->password == $client->password) {
            return 1;
        } else return null;
    }

}
