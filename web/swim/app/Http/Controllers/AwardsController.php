<?php

namespace App\Http\Controllers;

use Illuminate\Http\Request;
use App\Models\Awards;

class AwardsController extends Controller
{
    public function store(Request $request)
    {
        $validated = $request->validate([
            'award_title' => 'required',
            'award_text' => 'required',
            'award_image' => 'required|image|mimes:jpeg,jpg,png'

        ]);

        return $request;

        // Awards::create($validated);
    }

    public function receive()
    {
        $awards = Awards::all();
        return $awards;
    }

    public function edit(Request $request)
    {
        $award = Awards::find($request->id);
        $award->award_title = $request->title;
        $award->award_text = $request->text;
        $image = $request->file('image');
        $imageName = 'Award'.time().rand(1,1000).'.'.$image->extension();
        $image->move(public_path('award_images'), $imageName);
        $award->award_image = $imageName;
        $award->save();
        return ;
    }

    public function delete(Request $request)
    {
        return $request;
    }
}
