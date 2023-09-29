<?php

namespace App\Http\Controllers;

use Illuminate\Http\Request;
use App\Models\Boat;


class BoatsController extends Controller
{
    public function receive()
    {
        return Boat::with('images', 'owner')->get();
    }

    public function sell(Request $request)
    {
        $boat = Boat::find($request->id);
        $boat->status = 'sold';
        $boat->owner_id = $request->owner_id;
        $boat->save();
    }

    public function rent(Request $request)
    {
        $boat = Boat::find($request->id);
        $boat->status = $request->status;
        $boat->rented_id = $request->rented_id;
        $boat->rented_from = $request->rented_from;
        $boat->rented_to = $request->rented_to;
        $boat->save();
        return $boat;
    }

    public function latest()
    {
        return Boat::latest()->take(3)->get();
    }
}
