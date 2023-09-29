<?php

namespace App\Http\Controllers;

use App\Models\Client;
use Illuminate\Http\Request;

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

        $client = Client::create([
            'name' => $request->name,
            'surname' => $request->surname,
            'patron' => $request->patron,
            'email' => $request->email,
            'password' => $request->password
        ]);

        return json_encode($client);
    }

    public function login(Request $request)
    {
        $client = Client::where('email', $request->email)->first();
        if ($client && $request->password == $client->password) {
            return json_encode($client);
        } else return null;
    }

}
