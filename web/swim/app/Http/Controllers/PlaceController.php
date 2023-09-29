<?php

namespace App\Http\Controllers;

use App\Models\BoatImage;
use App\Models\Boat;
use Illuminate\Http\Request;

class PlaceController extends Controller
{
    public function store(Request $request)
    {
        $validated = $request->validate([
            'name' => 'required',
            'description' => 'required',
            'price' => 'required',
            'owner_id' => 'required',
            'files.*' => 'required|image|mimes:jpeg,jpg,png',
        ]);

        $newBoat = Boat::create([
            'name' => $request->name,
            'description' => $request->description,
            'owner_id' => $request->owner_id,
            'price' => $request->price,
            'rented_from' => null,
            'rented_to' => null,
            'status' => 'created'
        ]);

        foreach ($request->file('files') as $image) {
            $imageName = 'Yacht'.time().rand(1,1000).'.'.$image->extension();
            $image->move(public_path('boat_images'), $imageName);
            BoatImage::create([
                'boat_id' => $newBoat->id,
                'filename' => $imageName
            ]);

        }

    }
}
