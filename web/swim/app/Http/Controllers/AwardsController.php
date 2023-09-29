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
            'award_image' => 'image|mimes:jpeg,jpg,png'
        ]);
        $image = $request->file('award_image');
        $imageName = 'Award' . time() . rand(1, 1000) . '.' . $image->extension();
        $image->move(public_path('award_images'), $imageName);
        $validated['award_image'] = $imageName;
        if (Awards::create($validated))
            return response()->json(['success' => true]);
        return response()->json(['success' => false, 'errors' => ['asd' => 'dsa']]);
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
        if ($image) {
            $imageName = 'Award' . time() . rand(1, 1000) . '.' . $image->extension();
            $image->move(public_path('award_images'), $imageName);
            $award->award_image = $imageName;
        }

        $award->save();
        return response()->json(['success' => true]);
    }

    public function delete(Request $request)
    {
        $award = Awards::find($request->id);
        $award->delete();
    }
}
